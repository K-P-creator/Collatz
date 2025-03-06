#This will graph a bar graph for digits 1-9 for interations to reach 1

import matplotlib
import subprocess
import matplotlib.pyplot as plt

counts = []

for d in range(1,9):
    result = (subprocess.run(["collatz", str(d)], capture_output=True, text=True))
    try:
        res = int(result.stdout.strip())
        counts.append(res)
    except ValueError:
        print(f"Error Processing {d}, {result.stderr}")

    plt.bar(d, res, width=0.8, label="{d}")

plt.xlabel("Input Integer")
plt.ylabel("Recursive Repititions")

plt.title("1-9 Collatz")

plt.show()



print (counts)