// TCP CLIENT

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
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
	
	if (!(connect (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr))))
		cout <<"SUCCESS: CONNECTED TO SERVER\n\n";
	else {
		perror ("ERROR: SERVER CONNECTION");
		exit (EXIT_FAILURE);
	}
	
	cout<<"ENTER FILENAME TO OPEN:";
	char buffer [MAX], buff [MAX];
	while (1) {
		bzero (buff, sizeof (buff));
		bzero (buffer, sizeof (buffer));
		cout <<"\n> ";
		fgets (buff, MAX, stdin);
		write (sockfd, buff, sizeof (buff));
		if (!strncmp (buff, "exit", 4))
			break;
		FILE *ff = fopen ("index.html", "w");
		while (1) {
			bzero (buffer, sizeof (buffer));
			read (sockfd, buffer, sizeof (buffer));
			if (strncmp (buffer, "END", 3) == 0)
				break;
			fputs (buffer, ff);
		}
		fclose (ff);
		cout <<"FILE PROJECTED AS INDEX.HTML. OPENING FILE IN FIREFOX..." <<endl;
		system ("firefox index.html");
		int c = getchar ();
		system ("rm index.html");
	}
	cout <<"CLIENT EXIT\n";
	close (sockfd);
	return 0;
}
