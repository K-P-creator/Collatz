#plots the counts from counts.csv

import matplotlib
import matplotlib.pyplot as plt
import csv

i = 1
num = []
count = []

with open("data/counts.csv", mode='r') as file:
    reader = csv.reader(file)
    for row in reader:
        count.append(int(row[0]))
        num.append(int(i))
        i += 1

plt.scatter(num, count, s=0.5, color="blue")
plt.title("Iteration Count vs Input Number")
plt.ylabel("Counts")
plt.xlabel("Input")

plt.show()
