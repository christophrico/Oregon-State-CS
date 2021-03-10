# Christopher Rico
# Project 5
# CS475
# OSU ID: 933239746


from os import system

def main():
    datafile = "data.csv"
    speedupData = "speedupData.csv"

    #create the files
    with open(speedupData, "w") as f:
        f.write("Speedup Data (C++ Speed / SIMD SSE Speed)\n")

    #build list of array sizes to test
    arraySizes = list(range(1000, 100000, 10000))
    arraySizes += list(range(100000, 1000001, 100000))
    arraySizes += list(range(2000000, 32000001, 2000000))

    tests = ["SIMD SSE Multiplication vs C++ Multiplication",
             "SIMD SSE Mult/Reduction vs C++ Mult/Reduction"]

    for test in tests:
        with open(datafile, "a") as f:
            f.write("\nTesting {}\n".format(test))
        with open(speedupData, "a") as f:
            f.write("{}\n".format(test))
            f.write("Array Size,Peak Speedup,Average Speedup\n")

            for size in arraySizes:
                cmd = ("g++ -DARRSIZE={} -DTEST={} program5.cpp simd.p5.cpp -o"
                       "program5 -lm -fopenmp").format(size, tests.index(test))
                system(cmd)

                print("Executing test " + str(tests.index(test)) + " with array size " + str(size))
                cmd = "./program5 {} {}".format(datafile, speedupData)
                system(cmd)

                cmd = "rm -f program5"
                system(cmd)

if __name__ == "__main__":
    main()
