/*
Q.2. Write a Client-Server socket program to implement “TCP chat server”. 
(Description: Two client systems connected to one central server for connection establishment, communication / chat have to be done in client machines.)
*/

// TCP CHAT SERVER

#include <iostream>
#include <netdb.h>
//#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <unistd.h>

#define PORT 443

pthread_mutex_t mutex;
int clients [20];
int nn = 0;

using namespace std;

void sendToAll (char *msg, int curr) {
	pthread_mutex_lock (&mutex);
	for (int ii=0; ii<nn; ++ii)
		if (send (clients [ii], msg, strlen (msg), 0) < 0) {
			cout <<"FAIL: SEND MESSAGE TO CLIENT " <<ii <<endl;
			continue;
		}
	pthread_mutex_unlock (&mutex);
}

void *recvMsg (void *connfd) {
	int sockfd = *((int *) connfd);
	char msg [1000];
	int len;
	while ((len = recv (sockfd, msg, 1000, 0)) > 0) {
		msg [len] = '\0';
		sendToAll (msg, sockfd);
	}
	return 0;
}

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
	
	//Assigning IP and PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl (INADDR_ANY); // inet_addr ("127.0.0.1");
	servaddr.sin_port = htons (PORT);
	
	// Binding newly created socket to the given IP and verification
	if (!(bind (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr))))
		cout <<"SUCCESS: SERVER BINDED\n";
	else
		errorExit (2);
	
	// Server ready to listen and verification
	if (!listen (sockfd, 20))
		cout <<"SUCCESS: SERVER LISTENING\n";
	else
		errorExit (3);
	
	// Accepting Clients
	pthread_t recvt;
	int connfd;
	while (1) {
		if ((connfd = accept (sockfd, (struct sockaddr*)NULL, NULL)) >= 0) {
			pthread_mutex_lock (&mutex);
			clients [nn++] = connfd;
			// Creating Thread for each Client
			pthread_create (&recvt, NULL, &recvMsg, &connfd);
			pthread_mutex_unlock (&mutex);
		}
		else
			errorExit (4);
	}
	close (sockfd);
	return 0;
}
