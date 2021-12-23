# $ touch 1912160_lab2_4.sh
# Q.4. Write a C program or shell script to display file status using stat system call.

echo '
// 1912160_Lab2_4.c
// Q.4. Write a C program or shell script to display file status using stat system call.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

void fileStat (char const FileName [] ) {
	struct stat fileStat;
	stat (FileName, &fileStat);
	printf ("\nFILE DETAILS:\n");
	printf ("User ID: %d\n", fileStat.st_uid);
	printf ("File representing particular device: %u\n", (unsigned int) fileStat.st_rdev);
	printf ("Group ID: %u\n", (unsigned int) fileStat.st_gid);
	printf ("File Size: %ld bytes\n", fileStat.st_size);
	printf ("Total number of hard links: %u\n", (unsigned int) fileStat.st_nlink);	
	printf ("File was recently modified at: %s\n", ctime (&fileStat.st_mtime));
	printf ("File was recently accessed at: %s\n", ctime (&fileStat.st_atime));
	
}

int main () {
	char *FileName = 0;
	size_t FileSize = 0;
	ssize_t FileRead;
	
	printf ("Enter File Name: ");
	FileRead = getline (&FileName, &FileSize, stdin);
	if (FileName [FileRead - 1] == '"'\n'"')
		FileName [FileRead - 1] = 0;
		
	int FileOpen = open (FileName, O_RDONLY);
	if (FileOpen == -1) 
		exit (0);
		
	fileStat (FileName);
	free (FileName);
	return 0;
}

' > 1912160_Lab2_4.c
gcc 1912160_Lab2_4.c -o run
./run
rm 1912160_Lab2_4.c
rm run

# $ chmod +x 1912160_Lab2_4.sh
# $ ./1912160_Lab2_4.sh

	
