# Christopher Rico
# Project 2
# CS475
# OSU ID: 933239746

from os import system


threadCount = [1, 2, 4, 8, 12, 16]
padCount = [0]
fix = 2

def main():
  file = "data.csv"
  datafile = open(file, "w")

  datafile.write("FIX,NUMTHREADS,NUMPAD,Peak Mega Adds,Ave Mega Add\n")

  for threads in threadCount:
    #compile and run fix
    for pad in padCount:
      cmd = ("g++ -DNUMT={} -DFIX={} -DNUMPAD={} program3.cpp -o  program3 -O0 -lm -fopenmp").format(threads, fix, pad)
      system(cmd)
      print ("Test{}: {} threads and {} pads".format(fix, threads, pad))
      cmd = "./program3 {}".format(file)
      system(cmd)

      cmd = "rm -f program3"
      system(cmd)


if __name__ == "__main__":
    main()
