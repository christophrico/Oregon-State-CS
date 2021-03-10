# Christopher Rico
# Project 1
# CS475
# OSU ID: 933239746

from os import system
from multiprocessing import cpu_count


#edit the output data file name and number of threads/nodes here
dataFile = "data.csv"
numThreads = [1, 2, 4, 6, 8, 12, 16]
numNodes = [100, 200, 500, 1000, 2000, 5000, 10000, 20000]


#compile the code
cmd = ("g++ program1.cpp -o program1 -lm -fopenmp")
system(cmd)


#open the output file
with open(dataFile, "w") as f:
    f.write("Total processors available: {}".format(cpu_count()))
    #cmd = "nproc > data.csv"
    #os.system(cmd)
    f.write(("\nThreads,Nodes,Volume,Max MegaCalcs,Average MegaCalcs\n"))


#run the program with various thread and node inputs
for threads in numThreads:
    for nodes in numNodes:
        print("Running tests: " + str(threads) + " threads and " + str(nodes) + " nodes")
        cmd = "./program1 {} {} {}".format(dataFile, threads, nodes)
        system(cmd)

cmd = "cat data.csv"
system(cmd)
