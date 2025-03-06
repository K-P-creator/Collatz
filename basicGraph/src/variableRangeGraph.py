#this will graph recursive repititions for numbers min-max

import matplotlib
import statistics
from statistics import mean, median, mode
import matplotlib.pyplot as plt
import subprocess

counts = []
min = 100
max = 250

for d in range(min,max+1):
    result = subprocess.run(["collatz.exe", str(d)], capture_output=True, text=True)
    try:
        res = int(result.stdout.strip())
        counts.append(res)
    except ValueError:
        print(f"Error Proccessing: {d}, {result.stderr}")
    
    plt.bar(d, res, width=0.8, label="{d}")

print("Mean: ", mean(counts))
print("Mode: ", mode(counts))
print("Median: ", median(counts))

plt.xlabel("Input Integer")
plt.ylabel("Recursive Repititions")

plt.title(f"{min}-{max} Collatz")

plt.show()
    