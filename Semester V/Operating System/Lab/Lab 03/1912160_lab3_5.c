/*
$ touch 1912160_lab3_5.c

Q.5. Write a C program to simulate “cd” command using UNIX system call. There are different versions of cd command. You chose one and simulate it. Write the algorithm in a separate file and submit.
*/

#include <stdio.h>
#include <unistd.h>

int main () {
	char PathName [100];
	getcwd (PathName, 100);
	printf ("Current Directory Path: %s\n", PathName);
	chdir ("..");
	getcwd (PathName, 100);
	printf ("Parent Directory Path: %s\n", PathName);
	return 0;
}

// $ gcc 1912160_lab3_5.c -o run
// $ ./run
