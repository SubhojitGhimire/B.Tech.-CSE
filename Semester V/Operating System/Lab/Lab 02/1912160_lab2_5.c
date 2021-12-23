// $ touch 1912160_lab2_5.c
// Q.5. Write a C program or a shell script to open, display the contents of a directory, and close it using related system calls.

#include <stdio.h>
#include <sys/dir.h>
#include <dirent.h>

int main () {
	struct dirent *DirEntry;
	DIR *DirName = opendir (".");
	
	if (DirName) {		
		while ((DirEntry = readdir (DirName)) != NULL ) {
			printf (" %s\n", DirEntry -> d_name);
		}	 
	}
	return 0;
}

// $ gcc 1912160_lab2_5.c -o run
// $ ./run
