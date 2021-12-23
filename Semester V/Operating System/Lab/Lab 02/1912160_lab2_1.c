// $ touch 1912160_lab2_1.c
// Q.1. Write a C program to create a new child process using fork system call.

#include <stdio.h>
#include <unistd.h>

void childProcess () {
	fork ();
	printf ("First Child Process\n");
	fork ();
	fork ();
	printf ("Second Child Process\n");
}

int main () {
	childProcess ();
	// number of child processes created = 2^n ,where n is the number of fork () created.
	return 0;
}

// $ gcc 1912160_lab2_1.c -o run
// $ ./run
