#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "encDec.h"

int main() {
  int pipe_fd[2];
  pid_t pid;

  // Create two pipes.
  if (pipe(pipe_fd) == -1) {
    perror("pipe");
    exit(1);
  }

  // Fork the process.
  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  // Producer process.
  if (pid == 0) {
    // Close the read end of the pipe.
    close(pipe_fd[0]);

    // Read data from the input file, encode it, and write it to the pipe.
    char input_file[] = "filename.inpf";
    char output_file[] = "filename.done";

    FILE *ifp = fopen(input_file, "r");
    if (ifp == NULL) {
      perror("fopen");
      exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), ifp) != NULL) {
      // Encode the buffer.
      encode(buffer, sizeof(buffer));

      // Write the encoded buffer to the pipe.
      write(pipe_fd[1], buffer, sizeof(buffer));
    }

    fclose(ifp);

    // Close the write end of the pipe.
    close(pipe_fd[1]);

    // Read the processed data from the pipe and write it to the output file.
    FILE *ofp = fopen(output_file, "w");
    if (ofp == NULL) {
      perror("fopen");
      exit(1);
    }

    while (read(pipe_fd[0], buffer, sizeof(buffer)) > 0) {
      // Decode the buffer.
      decode(buffer, sizeof(buffer));

      // Write the decoded buffer to the output file.
      fputs(buffer, ofp);
    }

    fclose(ofp);

    exit(0);
  }

  // Consumer process.
  else {
    // Close the write end of the pipe.
    close(pipe_fd[1]);

    // Read the encoded data from the pipe and decode it.
    char buffer[1024];
    while (read(pipe_fd[0], buffer, sizeof(buffer)) > 0) {
      // Decode the buffer.
      decode(buffer, sizeof(buffer));

      // Convert all lowercase characters to uppercase.
      for (int i = 0; i < sizeof(buffer); i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
          buffer[i] = buffer[i] - 'a' + 'A';
        }
      }

      // Encode the converted buffer.
      encode(buffer, sizeof(buffer));

      // Write the encoded buffer to the pipe.
      write(pipe_fd[1], buffer, sizeof(buffer));
    }

    // Close the read end of the pipe.
    close(pipe_fd[0]);

    // Wait for the producer process to finish.
    wait(NULL);

    exit(0);
  }

  return 0;
}
