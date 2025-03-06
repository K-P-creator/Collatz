#Plots data in freq.csv 
#ONLY PLOTS POWERS OF TWO

import matplotlib
import matplotlib.pyplot as plt
import csv

def is_power_of_two(n):
    #bitwise and will find powers of two aka binary numbers
    #that only contain one 1
    return (n & (n - 1)) == 0


#first number per row
num = []

#second number per row
freq = []

with open("data/freq.csv", mode='r') as file:
    reader = csv.reader(file)
    for row in reader:
        if is_power_of_two(int(row[0])):
            num.append(int(row[0]))
            freq.append(int(row[1]))


plt.scatter(num,freq,s=1.5,color="red")
plt.xlabel("Number")
plt.ylabel("Frequency")
plt.title("Number vs Frequency")

plt.show()
