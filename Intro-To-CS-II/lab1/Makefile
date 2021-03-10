prog: main.o readMatrix.o determinant.o inputVal.o
	g++ main.o readMatrix.o determinant.o inputVal.o -o prog
	
main.o: main.cpp determinant.hpp readMatrix.hpp
	g++ -c main.cpp
	
determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp inputVal.cpp inputVal.hpp
	g++ -c readMatrix.cpp
	
inputVal.o: inputVal.cpp inputVal.hpp
	g++ -c inputVal.cpp
	
clean:
	rm *.o matrixFun a.out 