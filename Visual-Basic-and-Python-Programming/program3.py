import tkinter as tk
from tkinter import ttk

# Create the main window
root = tk.Tk()
root.title("Averages")

# Create functions
def calculate_average():
    """
    Calculate the average of the two highest scores from the input values.
    Handles error cases where input values are missing or invalid.
    """
    try:
        score1 = float(score1_entry.get())
        score2 = float(score2_entry.get())
        score3 = float(score3_entry.get())
    except ValueError:
        result_label.config(text="Invalid input. Please enter valid scores.")
        return

    if score1 < 0 or score1 > 100 or score2 < 0 or score2 > 100 or score3 < 0 or score3 > 100:
        result_label.config(text="Invalid input. Scores must be between 0 and 100.")
        return

    # Find the smallest score using three separate if statements
    smallest_score = score1
    if score2 < score1 and score2 < score3:
        smallest_score = score2
    elif score3 < score1 and score3 < score2:
        smallest_score = score3

    # Calculate the average of the two highest scores
    highest_scores = [score1, score2, score3]
    highest_scores.remove(smallest_score)
    average = sum(highest_scores) / 2

    result_label.config(text=f"Average: {average:.1f}")

# Create input fields
score1_label = ttk.Label(root, text="Score 1:")
score1_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")
score1_entry = ttk.Entry(root)
score1_entry.grid(row=0, column=1, padx=5, pady=5)

score2_label = ttk.Label(root, text="Score 2:")
score2_label.grid(row=0, column=2, padx=5, pady=5, sticky="w")
score2_entry = ttk.Entry(root)
score2_entry.grid(row=0, column=3, padx=5, pady=5)

score3_label = ttk.Label(root, text="Score 3:")
score3_label.grid(row=0, column=4, padx=5, pady=5, sticky="w")
score3_entry = ttk.Entry(root)
score3_entry.grid(row=0, column=5, padx=5, pady=5)

# Create calculate button
calculate_button = ttk.Button(root, text="Compute Average of Two Highest Scores", command=calculate_average)
calculate_button.grid(row=1, column=0, columnspan=6, padx=5, pady=5)

# Create result label
result_label = ttk.Label(root, text="")
result_label.grid(row=2, column=0, columnspan=6, padx=5, pady=5)

# Run the main event loop
root.mainloop()
