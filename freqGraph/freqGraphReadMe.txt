# Frequency Graphs Read Me

## Generating Data

This file contains implementations based upon measuring and plotting the frequencies
of value occurrence. I also implemented a new collatz function. Use the following to
generate data for a custom range of numbers

```sh
./collatzWithFrequency.exe "Min" "Max"


with min and max being the min and max integers for which you wish to calculate the
collatz data with. The c++ program will automatically output to two csv's, one to 
keep track of the frequencies and one to keep track of the counts.

Once you have generated your data, use py ./"script_name.py" to plot the data you
have generated. This makes it easy to take a look a different custom data sets.

I am using dot plots here as they are more conducive to larger amounts of data.
I also change my methodology in this file. the python scripts no longer run the
c++ executable, instead data calculated is stored in the persisting csv's. This
makes it much more efficient to produce multiple graphs

## Definitions
    ### Count
    The number of **recursive iterations** of the collatz function until 
    the output == 1

    ### Frequency
    The **number of occurrences** of a certain output during the 
    recursive function calls for the input sequence. AKA how
    many time 2 showed up as the output for the functions.

## Rundown On Graph Scripts

### plotCounts.py - 
    This will plot the counts from **counts.csv** in a dot plot. This data is
    very interesting to look at... I'm sure there is some meaning to the patter that appears
    I just have not figured it out yet...

    Take a look at my example graph of data from 1-1000
 
### powersOfTwoPlot.py - 
    This will plot the frequencies from **freq.csv for only the powers of two.** If you are familiar
    with the cojecture, the input number must be equal to a power of two at some point
    in order to be divided down to 2 and then 1. The frequencies here, and in the other
    frequency graphing script seem to follow the mirror of an exponential curve

### freqGraph.py - 
    This will plot all the frequencies from **freq.csv** for all numbers that have occurred. 
    Note that with large data sets this may take a while to generate the graph and the results
    may not tell very much as the points are very condensed. Try graphing smaller ranges,
    of perhaps 10-50 numbers. 

    I don't believe there is as much to be gained from these last two graphing methods as
    from the counts plot...

#### NOTE - 
    matplotlib has a *"zoom to rectangle"* feature that you access by clicking the 
    magnifying glass. Make sure to use this feature if you want to zoom in on specific
    parts of the graphs.