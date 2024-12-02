import tkinter as tk

# Function to determine the forecast
def determine_forecast():
    color = color_entry.get().upper()
    mode = mode_entry.get().upper()
    
    if color == "B" and mode == "S":
        forecast_label.config(text="Steady blue, clear view")
    elif color == "B" and mode == "F":
        forecast_label.config(text="Flashing blue, clouds due")
    elif color == "R" and mode == "S":
        forecast_label.config(text="Steady red, rain ahead")
    elif color == "R" and mode == "F":
        forecast_label.config(text="Flashing red, snow instead")
    else:
        forecast_label.config(text="Invalid input. Please enter B or R for color and S or F for mode.")

# Create the main window
root = tk.Tk()
root.title("Forecast")

# Create labels and entry fields
color_label = tk.Label(root, text="Color of the light (B or R):")
color_label.pack()

color_entry = tk.Entry(root)
color_entry.pack()

mode_label = tk.Label(root, text="Mode (S or F):")
mode_label.pack()

mode_entry = tk.Entry(root)
mode_entry.pack()

# Create the Determine Forecast button
determine_button = tk.Button(root, text="Determine Forecast", command=determine_forecast)
determine_button.pack()

# Create a label to display the forecast
forecast_label = tk.Label(root, text="")
forecast_label.pack()

# Run the main event loop
root.mainloop()
