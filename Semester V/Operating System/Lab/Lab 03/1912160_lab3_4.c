/*
$ touch 1912160_lab3_4.c

Q.4. Write a C program to simulate “rm” command using UNIX system call.
	Algorithm:
	1. Get filename as command-line argument.
	2. Open the file in read-only mode using read system call.
	3. If file does not exist, then stop.
	4. Close the file using close system call.
	5. Delete the file using unlink system call.
	6. Stop.
	7. [Output]: Thus files can be deleted in a manner similar to rm command. The deletion of file can be verified by using ls command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv []) {
	int file;
	if (argc == 2) {
		file = open (argv[1], O_RDONLY);
		if (file != -1) {
			close (file);
			unlink (argv[1]);
			printf ("File Deletion Success\n");
			exit (0);
		}
		else perror (argv[1]);
		printf ("gcc 1912160_lab3_4.c -o run\n");
		printf ("./run <filename>\n");
	}
	return 0;
}

// $ gcc 1912160_lab3_4.c -o run
// $ ./run 1912160_lab3_4.txt
