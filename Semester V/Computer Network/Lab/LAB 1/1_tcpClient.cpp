/*
Q.1. Write a Client-Server socket program to implement “TCP client server” architecture. 
(Description: Retrieve information (any text or system info) from TCP server to TCP client.)
*/

// TCP CLIENT

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 80
#define PORT 443

using namespace std;

void errorExit (int errorSignal) {
	cout <<"FAIL: ";
	if (errorSignal == 1)
		cout <<"SOCKET CREATING\n";
	else if (errorSignal == 2)
		cout <<"SERVER CONNECTION\n";
	exit (0);
}

int main () {
	// Socket creation and verification
	int sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	if (sockfd != -1)
		cout <<"SUCCESS: SOCKET CREATED\n";
	else
		errorExit (1);
	bzero (&servaddr, sizeof (servaddr));
	
	// Assigning IP and PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl (INADDR_ANY); // inet_addr ("127.0.0.1");
	servaddr.sin_port = htons (PORT);
	
	// Connecting to Server Socket
	if (!(connect (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr))))
		cout <<"SUCCESS: CONNECTED TO SERVER\n\n";
	else
		errorExit (2);
	
	// Message Exchange between Client and Server
	char buff [MAX];
	while (1) {
		bzero (buff, sizeof (buff));
		cout <<"WRITE CLIENT MESSAGE: ";
		for (int ii=0; (buff [ii] = getchar()) != '\n'; ++ii);
		write (sockfd, buff, sizeof (buff));
		if (!strncmp (buff, "exit", 4))
			break;
		bzero (buff, sizeof (buff));
		read (sockfd, buff, sizeof (buff));
		cout <<"SERVER MESSAGE: " <<buff;
	}
	cout <<"CLIENT EXIT\n";
	close (sockfd);
	return 0;
}
