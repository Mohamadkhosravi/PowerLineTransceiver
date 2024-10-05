import serial
import plotly.graph_objects as go
import time
import threading
import ipywidgets as widgets
from IPython.display import display

# Serial port configuration
serial_port = 'COM6'  # Replace with your actual port if needed
baud_rate = 9600
ser = serial.Serial(serial_port, baud_rate)

# Data storage and visualization setup
num_data_points = 100
max_points = 100  # Maximum data points displayed on the plot
data_values = []
fig = go.FigureWidget()
fig.add_scatter(name='Single Input')

def update_plot(data):
    data_values.append(data)

    # Limit the size of the array and remove old data
    if len(data_values) > max_points:
        data_values.pop(0)

    # Update the plot with new data
    with fig.batch_update():
        fig.data[0].y = data_values

def read_serial_data():
    while True:
        try:
            data_bytes = ser.readline()
            data_string = data_bytes.decode('utf-8', errors='replace').strip()
            data = float(data_string)  # Assuming the serial data is a single numerical value
            # Update the plot
            update_plot(data)
         #time.sleep(0.1)  # Adjust delay between data points as needed

        except Exception as e:
            print("An error occurred:", e)
            time.sleep(1)

# Create a widget to display output
out = widgets.Output()

# Start the thread for reading serial data
serial_thread = threading.Thread(target=read_serial_data)
serial_thread.start()

# Display the output and the plot
display(out)
with out:
    display(fig)
