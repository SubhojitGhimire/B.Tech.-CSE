// Client side implementation of FTP (uses UDP)
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
        perror ("FAIL: SOCKET CREATION");
        exit (EXIT_FAILURE);
    }
	cout <<"SUCCESS: SOCKET CREATED\n\n";
    memset(&servaddr, 0, sizeof(servaddr));
      
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
	char buffer[MAXLINE], command [MAXLINE];
	cout <<"ENTER COMMANDS";
    unsigned int nn, len;
	while (1) {
		memset (command, 0, MAXLINE);
		memset (buffer, 0, MAXLINE);
		cout <<"\n> ";
		fgets (command, MAXLINE, stdin);
		sendto (sockfd, (const char *)command, strlen(command), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		nn = recvfrom (sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
		buffer[nn] = '\0';
		if (strncmp (command, "exit", 4) == 0)
			break;
		cout << buffer <<endl;
	}
  
    close (sockfd);
    return 0;
}