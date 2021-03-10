# Christopher Rico
# Project 2
# CS475
# OSU ID: 933239746

from os import system
from multiprocessing import cpu_count


#edit the output data file name and number of threads/nodes here
dataFile = "data.csv"
numThreads = [1, 2, 4, 6, 8, 12, 16]


#compile the code
cmd = ("g++ program2.cpp -o program2 -lm -fopenmp")
system(cmd)


#open the output file
with open(dataFile, "w") as f:
    f.write(("Threads,Max MegaCalcs,Average MegaCalcs\n"))


#run the program with various thread and node inputs
for threads in numThreads:
    print("Running tests: " + str(threads) + " threads")
    cmd = "./program2 {} {}".format(dataFile, threads)
    system(cmd)

cmd = "cat data.csv"
system(cmd)

cmd = ("rm -f program2")
system(cmd)
