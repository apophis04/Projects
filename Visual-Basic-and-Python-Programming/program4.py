import tkinter as tk

# Function to determine honors based on GPA
def determine_honors():
    gpa = float(gpa_entry.get())
    if gpa < 2.0 or gpa > 4.0:
        result_label.config(text="Incorrect Input. Try again.")
    elif gpa >= 3.9:
        result_label.config(text="You graduated summa cum laude.")
    elif gpa >= 3.6:
        result_label.config(text="You graduated magna cum laude.")
    elif gpa >= 3.3:
        result_label.config(text="You graduated cum laude.")
    elif gpa >= 2.0:
        result_label.config(text="You graduated.")

# Create the main window
root = tk.Tk()
root.title("Honors")

# Create labels and entry field
gpa_label = tk.Label(root, text="GPA (2 through 4):")
gpa_label.pack()

gpa_entry = tk.Entry(root)
gpa_entry.pack()

# Create the Determine Honors button
determine_button = tk.Button(root, text="Determine Honors", command=determine_honors)
determine_button.pack()

# Create a label to display the result
result_label = tk.Label(root, text="")
result_label.pack()

# Run the main event loop
root.mainloop()
