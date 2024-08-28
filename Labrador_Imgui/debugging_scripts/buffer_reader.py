import csv
import matplotlib.pyplot as plt

with open('buffer.csv') as buffer_file:
    buffer_arr = csv.reader(buffer_file)
    for row in buffer_arr:
        for i,entry in enumerate(row):
            row[i] = int(entry)
        plt.plot(row[-10000:])
        plt.show()