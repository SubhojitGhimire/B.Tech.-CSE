// $ touch 1912160_lab2_2.c
// Q.2. Write a C program to block a parent process until child completes using wait system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void childProcess () {
	printf ("\nChild Process Running.\n");
	printf ("Child PPID: %d Child PID: %d\n", getppid (), getpid ());
	printf ("Child Process Completed.\n");
}

void parentProcess () {
	printf ("Parent Process Running.\n");
	printf ("Parent PID: %d\n", getpid ());
	printf ("Parent Process Suspended. Waiting for Child Process to Complete.\n");
	wait (0);
	printf ("\nParent Process Resumed.\n");
	printf ("Parent Process Completed.\n");	
}

int main () {
	pid_t pid = fork ();
	if (pid > 0) {
		parentProcess ();
	
	}
	else if (pid == 0) {
		childProcess ();	//return value zero means child process created
		exit (0);
	}
	else {
		printf ("Child Process Creation Failed.");
	}
	return 0;
}

// $ gcc 1912160_lab2_2.c -o run
// $ ./run
