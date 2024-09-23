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

    # Update plot with the last `max_points` data points
    with fig.batch_update():
        fig.data[0].y = data_values[-max_points:]

def read_serial_data():
    while True:
        try:
            data_bytes = ser.readline()
            data_string = data_bytes.decode('utf-8', errors='replace').strip()
            data = float(data_string)  # Assuming the serial data is a single numerical value

            # Data validation (optional, uncomment if needed)
            # if data <= 0:
            #     data = 1  # Replace with appropriate handling for invalid data

            # Data capping (optional, uncomment if needed)
            # if data > 1024:  # Adjust limit as necessary
            #     data = 1024

            update_plot(data)
            time.sleep(0.1)  # Adjust delay between data points as needed

        except Exception as e:
            print("An error occurred:", e)
            time.sleep(1)

out = widgets.Output()
serial_thread = threading.Thread(target=read_serial_data)
serial_thread.start()

display(out)
with out:
    display(fig)