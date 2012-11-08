all: sandbox

run: sandbox
	./sandbox

# Define Fortran compiler
FC= gfortran-4.8

sandbox: main.f func.o
	$(FC) -m64 -o sandbox main.f func.o -L/usr/local/cuda/lib -lcudart -finit-local-zero

func.o: func.cu
	nvcc -m64 -c -O3 func.cu

clean: 
	rm sandbox func.o
