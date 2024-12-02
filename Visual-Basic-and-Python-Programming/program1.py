import tkinter as tk

# Define constants
PENCE_PER_SHILLING = 12
SHILLINGS_PER_POUND = 20

# Function to convert pence to pounds, shillings, and pence
def convert_pence():
    # Get the input pence from the entry field
    pence_input = int(pence_entry.get())

    # Calculate the pounds, shillings, and remaining pence
    pounds = pence_input // (PENCE_PER_SHILLING * SHILLINGS_PER_POUND)
    remaining_pence = pence_input % (PENCE_PER_SHILLING * SHILLINGS_PER_POUND)
    shillings = remaining_pence // PENCE_PER_SHILLING
    pence = remaining_pence % PENCE_PER_SHILLING

    # Update the output fields with the result
    pounds_output.config(text=str(pounds))
    shillings_output.config(text=str(shillings))
    pence_output.config(text=str(pence))

# Create the main window
root = tk.Tk()
root.title("Coins")

# Create the input field for pence
pence_label = tk.Label(root, text="Number of pence to change:")
pence_label.pack()
pence_entry = tk.Entry(root)
pence_entry.pack()

# Create the "Convert to pounds, shillings, and pence" button
convert_button = tk.Button(root, text="Convert to pounds, shillings, and pence", command=convert_pence)
convert_button.pack()

# Create the output fields for pounds, shillings, and pence
pounds_label = tk.Label(root, text="Pounds:")
pounds_label.pack()
pounds_output = tk.Label(root, text="")
pounds_output.pack()

shillings_label = tk.Label(root, text="Shillings:")
shillings_label.pack()
shillings_output = tk.Label(root, text="")
shillings_output.pack()

pence_label = tk.Label(root, text="Pence:")
pence_label.pack()
pence_output = tk.Label(root, text="")
pence_output.pack()

# Start the main event loop
root.mainloop()
