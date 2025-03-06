#Plots data in freq.csv 
#powers of two will be plotted as red and with a bigger size 

import matplotlib
import matplotlib.pyplot as plt
import csv

#bitwise and will find powers of two aka binary numbers
#that only contain one 1
def is_power_of_two(n):
    return (n & (n - 1)) == 0


#first number per row
num = []

#second number per row
freq = []

with open("data/freq.csv", mode='r') as file:
    reader = csv.reader(file)
    for row in reader:
        num.append(int(row[0]))
        freq.append(int(row[1]))

colors = ["red" if is_power_of_two(val) else "blue" for val in num]
size = [1.5 if col == "red" else 0.2 for col in colors]

plt.scatter(num,freq,s=size,color=colors)
plt.xlabel("Number")
plt.ylabel("Frequency")
plt.title("Number vs Frequency")

plt.show()

