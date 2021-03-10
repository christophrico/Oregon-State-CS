<!-- HEADER -->
<br />
<p align="center">
  <h3 align="center">Intro to Computer Science II</h3>
  <p align="center">
    Programming coursework from Oregon State University CS 162 - Intro to Computer Science II
</p>


<!-- TABLE OF CONTENTS -->
## Table of Contents
* [About the Course](#about-the-course)
* [Getting Started](#getting-started)
* Coursework
 1. [OpenMP with 1 or 4 threads](./p0)
 2. [Volume calculations with 1-16 OpenMP threads](./p1)
 3. [Astrophysics calculations with 1-16 OpenMP threads](./p2)
 4. [Array ops using OpenMP](./p3)
 5. [Biological simulations with OpenMP](./p4)
 6. [SIMD SSE vs C++ MP](./p5)
 7. [MapReduce using OpenMP and CUDA](./p6)
 8. [OpemMP vs OpenCL vs SIMD autocorrelate](./p7)


---
<!-- ABOUT THE Course -->
## About The Course
Parallel processing paradigms and technologies, including OpenMP, OpenCL, SIMD, and CUDA.

---
<!-- GETTING STARTED -->
## Getting Started
To get a local copy up and running follow these simple steps.


#### Prerequisites
* gcc compiler: https://gcc.gnu.org/install/index.html
* Python 2.7 or higher

#### Usage
1. Clone the repo
```sh
git clone https://github.com/christophrico/Parallel-Programming.git
```
2. Compile desired program with make, if available
```sh
make
```
3. If Python script is available, run that
```sh
python3 ./<filename>
```
Otherwise, run makefile-generated file
```sh
./<filename>
