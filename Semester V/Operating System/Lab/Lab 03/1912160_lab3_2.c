/*
$ touch 1912160_lab3_2.c
Q.2. Write a C program to simulate "cp" command using UNIX system call.
	Algorithm:
	1. Get source and destination filename as command-line argument.
	2. Declare a buffer of size 1KB.
	3. Open the source file in read-only mode using open system call.
	4. If file does not exist, then stop.
	5. Create the destination file using creat system call.
	6. If file cannot be created, then stop.
	7. File copy is achieved as follows:
		a. Read 1KB data from source file and store onto buffer using read system call.
		b. Write the buffer contents onto destination file using write system call.
		c. If end-of-file then step 8 else step 7a.
	8. Close source and destination file using close system call.
	9. Stop.
	10. [Output]: Thus a file is copied using file I/O. The cmp command can be used to verify that contents of both file are same.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	int SrcFile, DestFile;
	char buffer [1024];
	int nread;
	
	if (argc == 3) {
		if ((SrcFile = open (argv[1], O_RDONLY)) != -1) {
			if ((DestFile = creat (argv[2], 0644)) != -1) {
				while ((nread = read (SrcFile, buffer, 1024))) {
					if (write (DestFile, buffer, nread) == -1) {
						exit (0);
					}
				}
				perror (argv [1]);
				exit (0);
			}
			perror (argv[1]);
			exit (0);
		}
		printf ("gcc 1912160_lab3_2.c -o run\n");
		printf ("./run <filename> <newfile>\n");
		exit (0);
	}
	close (SrcFile);
	close (DestFile);
	return 0;
}
		
// $ gcc 1912160_lab3_2.c -o run
// $ ./run 1912160_lab3_2.c 1912160_lab3_2_out.txt
