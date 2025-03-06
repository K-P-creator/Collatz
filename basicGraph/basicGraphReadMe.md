# Basic Graph Read Me

This folder contains my first implementations of the collatz function as well
as my first python graphing script. In the scripts here, we run the c++ .exe
inside of the script and capture the output. This will later be changed to include
databases for improved performance. The collatz main here also does not compute
more than one number at a time, and is called multiple times by the python script
using a single command line argument to pass the input integer to the exe

## Usage

Use

```sh
g++ -o collatz collatz.cpp
```

To generate the .exe to be called by the py scripts. Ensure you name the exe
using the -o flag or the scripts will not be able to find it.

Use

```sh
pip install matplotlib
py "scriptName.py"
```

## Definitions

### Count

The number of **recursive iterations** of the collatz function until 
the output == 1

### Frequency

The **number of occurrences** of a certain output during the 
recursive function calls for the input sequence. AKA how
many time 2 showed up as the output for the functions.

## Rundown of Graph Scripts

### oneDigGraph.py

This script will run the exe nine times, and graph the resultig counts for all 
the one digit numbers (1-9). I use a bar graph here which will later be changed
to a scatter plot for increased readability with large datasets

### variableRangeGraph.py

This script will graph a variable range of input data. You can set the range
by editing the min and max values inside this .py value. I also graph with 
a bar graph here.
