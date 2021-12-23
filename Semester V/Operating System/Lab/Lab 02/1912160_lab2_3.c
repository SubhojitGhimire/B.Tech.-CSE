// $ touch 1912160_lab2_3.c
// Q.2. Write a C program to load an executable program in a child processes exec system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void childProcess () {
	printf ("\nChild PPID: %d Child PID: %d\n", getppid (), getpid ());
	printf ("Child Process exec system call.\n");
	execl ("/bin/ls", "ls", NULL);
	exit (0);
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
	pid_t pid = fork();
	if (pid > 0) {
		parentProcess ();
	}
	else if (pid == 0) {
		childProcess ();
	}
	else {
		printf ("Child Process Creation Failed.\n");
	}
	return 0;
}

// $ gcc 1912160_lab2_3.c -o run
// $ ./run
