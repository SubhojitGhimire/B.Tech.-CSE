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
char fileContent [MAXLINE];

using namespace std;

int ftpFileProcess (char *fileName) {
	FILE *ff = fopen (fileName, "r");
	if (ff == NULL)
		return 0;
	int ii = 0;
	while (!feof (ff)) {
		fileContent [ii] = getc (ff);
		++ii;
	}
	fileContent [ii-1] = '\0';
    if (fileContent [0] == '\0')
        return 0;
    return 1;
}

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
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
        perror("FAIL: SERVER BIND\n");
        exit(EXIT_FAILURE);
    }
	cout <<"SUCCESS: SERVER BOUND\n";
    
	cout <<"SERVER LISTENING FOR MESSAGES TO ECHO BACK...\n\n";
	char buffer[MAXLINE];
    unsigned int len, nn;
    len = sizeof(cliaddr);  //len is value/resuslt
	while (1) {
		memset (buffer, 0, MAXLINE);
		bzero (fileContent, MAXLINE);
		nn = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
		buffer[nn] = '\0';
		cout <<"REQUEST RECEIVED: OPENING FILE " <<buffer;
		buffer [nn-1] = '\0';
		if (ftpFileProcess (buffer)) {
			memset (buffer, 0, MAXLINE);
			strcpy (buffer, fileContent);
		}
		else {
			memset (buffer, 0, MAXLINE);
			strcpy (buffer, "ERROR: FILE EITHER EMPTY OR DOES NOT EXIST");
		}		
		sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
	}
    
	close (sockfd);
    return 0;
}