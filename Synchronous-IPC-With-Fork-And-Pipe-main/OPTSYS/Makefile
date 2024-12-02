# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = $(wildcard *.c)

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable
EXECUTABLES = producer consumer

# Targets
all: $(EXECUTABLES)

producer: producer.o encDec.o
	$(CC) $(CFLAGS) -o $@ $^

consumer: consumer.o encDec.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXECUTABLES)
