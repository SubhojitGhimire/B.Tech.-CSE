// Server side implementation of Connectionless Iterative Service (uses UDP)
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
char fact [MAXLINE];

using namespace std;

int multiply (int xx, int res[], int resSize) {
    int carry = 0;
	for (int ii=0; ii < resSize; ++ii) {
        int prod = res[ii] * xx + carry;
        res[ii] = prod % 10; 
        carry  = prod / 10;   
    }
    while (carry) {
        res [resSize] = carry % 10;
        carry = carry / 10;
        ++resSize;
    }
    return resSize;
}

void factorial (int number) {
    int res [MAXLINE];
	char numToTxt [5];
    res [0] = 1;
    int resSize = 1;
    for (int xx=2; xx <= number; ++xx)
        resSize = multiply (xx, res, resSize);
    for (int ii=resSize-1; ii >= 0; --ii) {
		sprintf (numToTxt, "%d", res[ii]);
		strcat (fact, numToTxt);
	}
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
		bzero (fact, MAXLINE);
		nn = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
		buffer[nn] = '\0';
		cout <<"REQUEST RECEIVED: FACTORIAL OF " <<buffer;
		int num = atoi (buffer);
		factorial (num);
		bzero (buffer, MAXLINE);
		strcpy (buffer, fact);
		sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
	}
    
	close (sockfd);
    return 0;
}