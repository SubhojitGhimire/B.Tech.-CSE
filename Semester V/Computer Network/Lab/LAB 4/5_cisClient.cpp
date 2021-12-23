// Client side implementation of Connectionless Iterative Service (uses UDP)
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
	cout <<"ENTER NUMBER WHOSE FACTORIAL IS TO BE FOUND";
    unsigned int nn, len;
	while (1) {
		memset (msg, 0, MAXLINE);
		memset (buffer, 0, MAXLINE);
		cout <<"\n> ";
		fgets (msg, MAXLINE, stdin);
		sendto (sockfd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		nn = recvfrom (sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
		buffer[nn] = '\0';
		if (strncmp (msg, "exit", 4) == 0)
			break;
		cout <<"FACTORIAL IS : " <<buffer;
	}
  
    close (sockfd);
    return 0;
}