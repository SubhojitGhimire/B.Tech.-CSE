/*
Q.3. Write a socket program to implement “Go-Back-N Protocol” using TCP.
*/

// GBN SERVER

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <unistd.h>

#define windowSize 3
#define frameNumber 50
#define lossRate 10
#define PORT 443

using namespace std;

char buffer [10];
char timeOutMsg [] = "Time Out!";

void gbnGenerate (int ack) {
    int ii = 0, jj, kk = ack, ll;
    while (kk > 0) {
        ii++;
        kk = kk / 10;
    }
    ll = ii--;
    while (ack > 0) {
        kk = ack % 10;
        buffer [ii--] = kk + 48;
        ack = ack / 10;
    }
    buffer [ll] = '\0';
}

void errorExit (string errorSignal) {
	cout << "FAIL: " << errorSignal << endl;
	exit (0);
}

int main() {
	
	// Socket creation and verification
	int sockfd = socket (AF_INET, SOCK_STREAM, 0);		
	struct sockaddr_in gbnServAddr;
	if (sockfd != -1)
		cout <<"SUCCESS: SOCKET CREATED\n";
	else
		errorExit ("SOCKET CREATING");
	bzero (&gbnServAddr, sizeof (gbnServAddr));
	
	// Assigning IP and PORT
	gbnServAddr.sin_family = AF_INET;
	gbnServAddr.sin_addr.s_addr = htonl (INADDR_ANY);
	gbnServAddr.sin_port = htons (PORT);
	
	// Binding newly created socket to the given IP and verification
	if (!(bind (sockfd, (struct sockaddr *) &gbnServAddr, sizeof (gbnServAddr))))
		cout <<"SUCCESS: SOCKET BINDED\n";
	else
		errorExit ("SOCKET BINDING");
	
	// Server ready to listen and verification
	struct sockaddr_in gbnClntAddr;							// Client address
	unsigned int cliAddrLen;								// Length of incoming message
	if (!(listen (sockfd, 5)))
		cout <<"SUCCESS: SERVER LISTENING\n";
	else
		errorExit ("SERVER LISTENING");
	cliAddrLen = sizeof (gbnClntAddr);
	
	// Accepting the data packet from client and verification	
	int connfd = accept (sockfd, (struct sockaddr*) &gbnClntAddr, &cliAddrLen);
	if (connfd >= 0)
		cout <<"SUCCESS: CLIENT ACCEPTED\n\n";
	else
		errorExit ("SERVER ACCEPTING");
	
	//Go-Back-N Implementation
	unsigned int timeOut = (unsigned int) time (NULL);
	srand (timeOut);
	recv (connfd, buffer, sizeof (buffer), 0);
	
    int buffValue = atoi (buffer);
	int ii, ack = 1, frameDrop;
    while (1) {
        for (ii = 0; ii < windowSize; ++ii) {
            recv (connfd, buffer, sizeof (buffer), 0);
            if (strncmp (buffer, timeOutMsg, 10) == 0)
                break;
        }
        ii = 0;
        while (ii < windowSize) {
            frameDrop = rand() % frameNumber;
            if(frameDrop < lossRate) {
                send (connfd, timeOutMsg, sizeof(timeOutMsg), 0);
                break;
            }
            else {
                gbnGenerate (ack);
                if (ack <= buffValue+1) {
                    cout << "\nFRAME RECEIVED: " << buffer;
                    send (connfd, buffer, sizeof (buffer), 0);
                }
                else
                    break;
                ++ack;
            }
            if (ack > buffValue)
                break;
            ++ii;
        }
    }
	
	cout << "SUCCESS: SERVER EXIT\n";
    close (sockfd);
    return 0;
}