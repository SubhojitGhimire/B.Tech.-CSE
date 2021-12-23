/*
Q.4. Write an “Echo Client” and “Echo Server” using UDP to estimate the round trip Time from client to the server. The server should be such that it can accept multiple connections at anygiven time. 
(Description: Multiple clients connected at the same time to one server for connection establishment, server has to listen to all the clients, use I/O monitoring calls if required.)
*/

// Client side implementation of UDP client-server model

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctime>
  
#define PORT 1194
#define MAXLINE 1024
  
using namespace std; 

// Driver code
int main (int argc, char *argv[]) {
	clock_t start, end;
	double cpuTimeUsed;
	
    int sockfd;
    struct sockaddr_in servaddr;
  
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror ("FAIL: SOCKET CREATION\n");
        exit (EXIT_FAILURE);
    }
	cout <<"SUCCESS: SOCKET CREATED\n\n";
    memset(&servaddr, 0, sizeof(servaddr));
      
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
	char buffer[MAXLINE];
	char msg [MAXLINE];
	char clientName [10];
	strcpy (clientName, argv [1]);
	cout <<"SEND MESSAGES\n";
    unsigned int n, len;
	while (1) {
		memset (msg, 0, MAXLINE);
		memset (buffer, 0, MAXLINE);
		cout <<"> ";
		fgets (msg, MAXLINE, stdin);
		start = clock ();
		sendto(sockfd, (const char *)clientName, strlen(clientName), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		sendto(sockfd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
		buffer[n] = '\0';
		sleep (1);
		end = clock ();
		cout <<"ECHO : " <<buffer;
		cpuTimeUsed = ((double) (end-start)) / CLOCKS_PER_SEC;
		cout <<"RTT: " <<cpuTimeUsed*1000 <<" millisecond\n\n";
		if (strncmp (msg, "exit", 4) == 0)
			break;
	}
  
    close (sockfd);
    return 0;
}