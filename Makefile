all: main.c IntVector.c IntVector.h
	gcc -Wall -o m IntVector.c main.c
