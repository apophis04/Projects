import tkinter as tk
from tkinter import ttk

# Create the main window
root = tk.Tk()
root.title("Ounces")

# Create functions
def calculate_price_per_ounce():
    """
    Calculate the price per ounce based on the input values.
    Handles error cases where input values are missing or invalid.
    """
    try:
        price = float(price_entry.get())
        pounds = int(pounds_entry.get())
        ounces = int(ounces_entry.get())
    except ValueError:
        result_label.config(text="Invalid input. Please enter valid values.")
        return

    if price <= 0 or (pounds == 0 and ounces == 0):
        result_label.config(text="Invalid input. Price and weight must be positive.")
        return

    total_ounces = pounds * 16 + ounces
    price_per_ounce = price / total_ounces
    result_label.config(text=f"Price per ounce: ${price_per_ounce:.2f}")

# Create input fields
price_label = ttk.Label(root, text="Price of item:")
price_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")
price_entry = ttk.Entry(root)
price_entry.grid(row=0, column=1, padx=5, pady=5)

weight_label = ttk.Label(root, text="Weight")
weight_label.grid(row=1, column=0, padx=5, pady=5, sticky="w")

pounds_label = ttk.Label(root, text="Pounds:")
pounds_label.grid(row=2, column=0, padx=5, pady=5, sticky="e")
pounds_entry = ttk.Entry(root)
pounds_entry.grid(row=2, column=1, padx=5, pady=5)

ounces_label = ttk.Label(root, text="Ounces:")
ounces_label.grid(row=3, column=0, padx=5, pady=5, sticky="e")
ounces_entry = ttk.Entry(root)
ounces_entry.grid(row=3, column=1, padx=5, pady=5)

# Create calculate button
calculate_button = ttk.Button(root, text="Calculate price per ounce", command=calculate_price_per_ounce)
calculate_button.grid(row=4, column=0, columnspan=2, padx=5, pady=5)

# Create result label
result_label = ttk.Label(root, text="")
result_label.grid(row=5, column=0, columnspan=2, padx=5, pady=5)

# Run the main event loop
root.mainloop()
