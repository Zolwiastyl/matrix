# Mój plik makefile - wpisz 'make all' aby skompilować cały program
# (właściwie wystarczy wpisać 'make' - all jest domyślny jako pierwszy cel)
CC = gcc  
FLAGS = -lm

all: main.o matrix.o
	$(CC) main.o matrix.o -o MatrixCounter $(FLAGS)

pierwszy.o: main.c
	$(CC) main.c -c -o main.o

matrix.o: matrix.c matrix.h
	$(CC) matrix.c -c -o matrix.o
