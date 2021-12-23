/*
Q.4. Write an “Echo Client” and “Echo Server” using UDP to estimate the round trip Time from client to the server. The server should be such that it can accept multiple connections at anygiven time. 
(Description: Multiple clients connected at the same time to one server for connection establishment, server has to listen to all the clients, use I/O monitoring calls if required.)
*/

// Server side implementation of UDP client-server model

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
  
#define PORT 1194
#define MAXLINE 1024

using namespace std;

// Driver code
int main () {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
      
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("FAIL: SOCKET CREATION\n");
        exit(EXIT_FAILURE);
    }
	cout <<"SUCCESS: SOCKET CREATED\n";
      
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
      
    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
      
    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
            sizeof(servaddr)) < 0 )
    {
        perror("FAIL: SERVER BIND\n");
        exit(EXIT_FAILURE);
    }
	cout <<"SUCCESS: SERVER BOUND\n";
    
	cout <<"SERVER LISTENING FOR MESSAGES TO ECHO BACK...\n\n";
	char buffer[MAXLINE];
    unsigned int len, n;
    len = sizeof(cliaddr);  //len is value/resuslt
	while (1) {
		memset (buffer, 0, MAXLINE);
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
		buffer[n] = '\0';
		cout <<"\n" <<buffer <<" : ";
		memset (buffer, 0, MAXLINE);
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
		buffer[n] = '\0';
		cout <<buffer;
		sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
		cout <<"ECHO SENT.\n"; 
	}
    
	close (sockfd);
    return 0;
}