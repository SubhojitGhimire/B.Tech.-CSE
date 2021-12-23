// Server side implementation of FTP (uses UDP)
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
  
#define PORT 1194
#define MAXLINE 1024

using namespace std;

// Driver code
int main () {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
      
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("FAIL: SOCKET CREATION");
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
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
        perror("FAIL: SERVER BIND");
        exit(EXIT_FAILURE);
    }
	cout <<"SUCCESS: SERVER BOUND\n";
    
	cout <<"SERVER LISTENING FOR INCOMING MESSAGES...\n\n";
	char buffer[MAXLINE];
	char command [MAXLINE+15];
    unsigned int len, nn;
    len = sizeof(cliaddr);  //len is value/resuslt
	while (1) {
		memset (buffer, 0, MAXLINE);
		bzero (command, MAXLINE);
		nn = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
		buffer[nn] = '\0';
		cout <<"REQUEST RECEIVED. EXECUTING COMMAND:  " <<buffer;
		strcpy (command, buffer);
		nn = strlen (command);
		command [nn-1] = '\0';
		strcat (command, " > result.txt");
		system (command);
		FILE *ff = fopen ("result.txt", "r");
		bzero (buffer, MAXLINE);
		for (nn=0; !feof (ff); ++nn)
			buffer [nn] = getc (ff);
		buffer [nn-1] = '\0';
		cout <<"SUCCESS: RESULT SENT BACK TO CLIENT" <<endl <<endl;
		sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
	}
    
	close (sockfd);
    return 0;
}