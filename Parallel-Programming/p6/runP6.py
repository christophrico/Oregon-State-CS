#Christopher Rico
#Project 6
#CS475
#OSU ID: 933239746


from os import system

localSizes = [1, 32, 64, 128, 160, 256, 320, 512, 640, 800, 1024]
mGlobalSizes = [1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000, 2048000, 4096000, 8192000]
rGlobalSizes = [1000000, 1640000, 2280000,2920000, 3560000, 4200000, 4840000, 5480000, 6120000, 6760000, 7400000, 8040000, 8680000]

def main():
    dataFile = "data.csv"

    #set up input file
    with open(dataFile, "w") as f:
        f.write("Operation,Local Size,Global Size,Num Work Groups,Expected Sum,Actual Sum,Performance (GigaOperations/S)\n")

    #run first and mult_add with a variety of local/global sizes
    for localSize in localSizes:
        for globalSize in mGlobalSizes:

            cmd = ("g++ -DLOCAL_SIZE={} -DGLOBAL_SIZE={} -o mult mult_add.cpp "
            "/scratch/cuda-7.0/lib64/libOpenCL.so -lm -fopenmp").format(localSize, globalSize)
            system(cmd)
            print("Running first at local size " + str(localSize) + " and global size " + str(globalSize))
            cmd = "./mult {} mult.cl".format(dataFile)
            system(cmd)

            cmd = ("g++ -DLOCAL_SIZE={} -DGLOBAL_SIZE={} -o mult_add mult_add.cpp "
            "/scratch/cuda-7.0/lib64/libOpenCL.so -lm -fopenmp").format(localSize, globalSize)
            system(cmd)
            print("Running mult_add at local size " + str(localSize) + " and global size " + str(globalSize))
            cmd = "./mult_add {} mult_add.cl".format(dataFile)
            system(cmd)

    #run mult_reduce with a variety of global sizes
    for globalSize in rGlobalSizes:
        cmd = ("g++ -DGLOBAL_SIZE={} -o mult_reduce mult_reduce.cpp "
        "/scratch/cuda-7.0/lib64/libOpenCL.so -lm -fopenmp").format(globalSize)
        system(cmd)
        print("Running mult_reduce at global size " + str(globalSize))
        cmd = "./mult_reduce {} mult_reduce.cl".format(dataFile)
        system(cmd)

    cmd = "rm -f mult mult_add mult_reduce"
    system(cmd)


if __name__ == "__main__":
    main()
