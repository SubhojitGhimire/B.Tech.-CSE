/*
$ touch 1912160_lab3_1.c
Q.1. Write a C program to simulate "ls" command using UNIX system calls.
	Algorithm:
	1. Store path of current working directory using getcwd system call.
	2. Scan directory of the stored path using scandir system call and sort the resultnat array of structure.
	3. Display dname member for all entries if it is not a hidden file.
	4. Stop.
	5. [Output]: The filenames/subdirectories are listed, similar to ls command.
*/

# include <stdio.h>
# include <dirent.h>
# include <unistd.h>

int main () {
	struct dirent **FileName;
	int n;
	char PathName [100];
	
	getcwd (PathName, 100);
	n = scandir (PathName, &FileName, 0, alphasort);
	if (n >= 0)
		for (int i=0; i<n; ++i)
			if (FileName[i] -> d_name[0] != '.')
				printf ("%-20s\n", FileName[i] -> d_name);
	return 0;
}

// $ gcc 1912160_lab3_1.c -o run
// $ ./run