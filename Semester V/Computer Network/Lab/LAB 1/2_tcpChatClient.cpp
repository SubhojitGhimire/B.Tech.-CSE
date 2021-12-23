/*
Q.2. Write a Client-Server socket program to implement “TCP chat server”. 
(Description: Two client systems connected to one central server for connection establishment, communication / chat have to be done in client machines.)
*/

// TCP CHAT CLIENT

#include <iostream>
#include <netdb.h>
// #include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <unistd.h>

#define PORT 443

char msg [1000];

using namespace std;

void *recvMsg (void *connfd) {
	int sockfd = *((int *)connfd);
	int len;
	//Client Thread Always Ready to Receive Message
	while ((len = recv (sockfd, msg, 1000, 0)) > 0) {
		msg [len] = '\0';
		fputs (msg, stdout);
	}
	return 0;
}

void errorExit (int errorSignal) {
	cout <<"FAIL: ";
	if (errorSignal == 1)
		cout <<"SOCKET CREATING\n";
	else if (errorSignal == 2)
		cout <<"SERVER CONNECTION\n";
	exit (0);
}

int main (int argc, char *argv[]) {
	//Socket creation and verification
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
		cout <<"SUCCESS: CONNECTED TO SERVER\n";
	else
		errorExit (2);
	
	// Creating a client thread aleays waiting for message
	pthread_t recvt;
	pthread_create (&recvt, NULL, &recvMsg, &sockfd);
	
	// Ready to receive message fro console
	int len;
	char sendMsg [1000], clientName [100];
	strcpy (clientName, argv [1]);
	while (fgets (msg, 500, stdin) > 0) {
		strcpy (sendMsg, clientName);
		strcat (sendMsg, ":");
		strcat (sendMsg, msg);
		len = write (sockfd, sendMsg, strlen (sendMsg));
		if (len < 0)
			cout <<"FAIL: MESSAGE SEND\n";
		if (!strncmp ("exit", msg, 4))
			break;
	}
	
	// pthread_join (recvt, NULL);
	close (sockfd);
	return 0;
}
