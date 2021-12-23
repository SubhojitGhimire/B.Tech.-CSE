/*
$ touch 1912160_lab3_3.c
Q.3. Write a C program to simulate "grep" command using UNIX system call.
	Algorithm:
	1. Get filename and search string as command-ling argument.
	2. Open the file in read-only mode using open system call.
	3. If file does not exist, then stop.
	4. Let length of the search string be n.
	5. Read line-by-line until end-of-file.
		a. Check to find out the occurrence of the search string in a line by examining characters in the range 1-n, 2-n+1, etc.
		b. If search string exists, then print the line.
	6. Close the file using close system call.
	7. Stop.
	8. [Output]: The program simulates grep command by listing lines conatining the search text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	FILE *file;
	char str[100], c, temp[30];
	int i, j, k, l, flag;
	
	if (argc == 3) {
		file = fopen (argv[2], "r");
		if (file != NULL) {
			while (!feof (file)) {
				i = 0;
				while (1) {
					c = fgetc (file);
					if (feof (file)) {
						str [i++] = '\0';
						break;
					}
					if (c == '\n') {
						str [i++] = '\0';
						break;
					}
					str [i++] = c;
				}
				if (strlen (str) >= strlen (argv[1]))
					for (k=0; k<=strlen(str) - strlen (argv[1]); ++k) {
						for (l=0; l<strlen(argv[1]); ++l)
							temp[l] = str[k+l];
						temp[l] = '\0';
						if (strcmp (temp, argv[1]) == 0) {
							printf ("%s\n", str);
							break;
						}
					}
			}
			exit (0);
		}
		printf ("gcc 1912160_lab3_3.c -o run\n");
		printf ("./run <search_text> <filename>\n");
		exit (0);
	}
	return 0;
}

// gcc 1912160_lab3_3.c -o run
// ./run temp 1912160_lab3_3.c				
