// TCP SERVER

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 1024
#define PORT 8080

using namespace std;

int main () {
	int sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	if (sockfd != -1)
		cout <<"SUCCESS: SOCKET CREATED\n";
	else {
		perror ("ERROR: SOCKET CREATION");
		exit (EXIT_FAILURE);
	}
	bzero (&servaddr, sizeof (servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl (INADDR_ANY);
	servaddr.sin_port = htons (PORT);
	
	if (!(bind (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr))))
		cout <<"SUCCESS: SOCKET BINDED\n";
	else {
		perror ("ERROR: SOCKET BINDING");
		exit (EXIT_FAILURE);
	}
	
	struct sockaddr_in cli;
	unsigned int len = sizeof (cli);
	if (!(listen (sockfd, 5)))
		cout <<"SUCCESS: SERVER LISTENING\n";
	else {
		perror ("ERROR: SERVER LISTEN");
		exit (EXIT_FAILURE);
	}
	
	int connfd = accept (sockfd, (struct sockaddr*)&cli, &len);
	if (connfd >= 0)
		cout <<"SUCCESS: CLIENT ACCEPTED\n\n";
	else {
		perror ("ERROR: CLIENT ACCEPTION");
		exit (EXIT_FAILURE);
	}
	
	char buffer[MAX], buff[MAX];
	while (1) {
		bzero (buffer, MAX);
		bzero (buff, MAX);
		read (connfd, buffer, sizeof (buffer));
		strcpy (buff, buffer);
		buff [strlen (buff) - 1] = '\0';
		cout << "REQUEST RECEICVED: " << buff <<endl;
		if (!strncmp (buff, "exit", 4))
			break;
		FILE *ff = fopen (buff, "r");
		while (!feof (ff)) {
			bzero (buffer, MAX);
			fgets (buffer, MAX, ff);
			write (connfd, buffer, sizeof (buffer));
		}
		fclose (ff);
		bzero (buffer, MAX);
		strcpy (buffer, "END");
		write (connfd, buffer, sizeof (buffer));
	}
	cout <<"SERVER EXIT\n";
	close (sockfd);
	return 0;
}
