/*
Q.1. Write a Client-Server socket program to implement “TCP client server” architecture. 
(Description: Retrieve information (any text or system info) from TCP server to TCP client.)
*/

// TCP SERVER

#include <iostream> // for cout
#include <cstdlib> // for exit()
#include <cstring> // for strncmp ()
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h> // for socket() and bind ()
#include <sys/types.h>
#include <unistd.h> // for close()

#define MAX 80
#define PORT 443

using namespace std;

void errorExit (int errorSignal) {
	cout <<"FAIL: ";
	if (errorSignal == 1)
		cout <<"SOCKET CREATING\n";
	else if (errorSignal == 2)
		cout <<"SOCKET BINDING\n";
	else if (errorSignal == 3)
		cout <<"SERVER LISTENING\n";
	else if (errorSignal == 4)
		cout <<"SERVER ACCEPTING\n";
	exit (0);
}

int main () {
	// socket creation and verification
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
	
	// Binding newly created socket to given IP and verification
	if (!(bind (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr))))
		cout <<"SUCCESS: SOCKET BINDED\n";
	else
		errorExit (2);
	
	// Server ready to listen and verification
	struct sockaddr_in cli;
	unsigned int len = sizeof (cli);
	if (!(listen (sockfd, 5)))
		cout <<"SUCCESS: SERVER LISTENING\n";
	else
		errorExit (3);
	
	// Accepting the data packet from client and verificaiton
	int connfd = accept (sockfd, (struct sockaddr*)&cli, &len);
	if (connfd >= 0)
		cout <<"SUCCESS: CLIENT ACCEPTED\n\n";
	else
		errorExit (4);
	
	// Message Exchange between Client and Server
	char buff[MAX];
	while (true) {
		bzero (buff, MAX);
		read (connfd, buff, sizeof (buff)); //read msg frm client cpy in buffer
		cout <<"CLIENT MESSAGE: " <<buff;
		bzero (buff, MAX);
		
		//write server message and send to client
		cout <<"WRITE SERVER MESSAGE: ";
		for (int ii=0; (buff [ii] = getchar ()) != '\n'; ++ii);
		write (connfd, buff, sizeof (buff));	
		if (!strncmp ("exit", buff, 4))
			break;
	}
	cout <<"SERVER EXIT\n";
	close (sockfd);
	return 0;
}
