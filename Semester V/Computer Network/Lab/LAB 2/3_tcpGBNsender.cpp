/*
Q.3. Write a socket program to implement “Go-Back-N Protocol” using TCP.
*/

// GBN CLIENT

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <unistd.h>

#define PORT 443
#define windowSize 3

using namespace std;

char buffer [10];							// a buffer
char timeOutMsg [] = "Time Out!";			// b timeOutMsg

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

int main () {
	// Socket Creation and verification
	int sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in gbnServAddr;
	if (sockfd != -1)
		printf ("SUCCESS: SOCKET CREATED\n");
	else
		errorExit ("SOCKET CREATION");
	bzero (&gbnServAddr, sizeof (gbnServAddr));
	
	
	// Assigning IP and PORT
	gbnServAddr.sin_family = AF_INET;
	gbnServAddr.sin_addr.s_addr = htonl (INADDR_ANY);
	gbnServAddr.sin_port = htons (PORT);
	
	// Connecting to Server Socket	
	if (!(connect (sockfd, (struct sockaddr*) &gbnServAddr, sizeof (gbnServAddr))))
			printf ("SUCCESS: CONNECTED TO SERVER\n\n");
	else
			errorExit ("SERVER CONNECTION");
	
	
	// Go-Back-N Implementation
	int frameNumber;
	cout << endl;
    cout << "Enter the number of Frames: ";
    cin >> frameNumber;
	cout << endl;
    gbnGenerate (frameNumber);
    send (sockfd, buffer, sizeof (buffer), 0);
	
	int ack = 1, ii, windowTemp, bufferValue = 0, gbN = 0, flag;
    while (1) {
        for(ii = 0; ii < windowSize; ii++) {
            gbnGenerate (ack);
            send (sockfd, buffer, sizeof(buffer), 0);
            if( ack <= frameNumber) {
                cout << "FRAME SENT " << ack << endl;
				ack++;
            }
        }
		sleep (3);
        ii = 0;
        windowTemp = windowSize;
        while (ii < windowSize) {
            recv (sockfd, buffer, sizeof (buffer), 0);
            bufferValue = atoi (buffer);
            if (strcmp (buffer, timeOutMsg) == 0) {
                gbN = ack - windowTemp;
				if ( gbN < frameNumber) {
					cout << "\n\nTIME OUT. RESEINDING FRAMES " << gbN <<" ONWARDS" << endl;
				}
				sleep (3);
				break;
            }
            else {
                if (bufferValue <= frameNumber) {
                    cout << "FRAME ACKNOWLEDGED. FRAME SEQUENCE:  " << buffer << endl;
                    windowTemp--;
                }
                else
					break;
				flag = atoi (buffer);
				if (flag == frameNumber)
					break;
            }
			
            if (bufferValue > frameNumber)
                break;
            ii++;
        }
		
        if (windowTemp == 0 && ack > frameNumber) {
            send (sockfd, timeOutMsg, sizeof(timeOutMsg), 0);
            break;
        }
        else {
            ack = ack - windowTemp;
            windowTemp = windowSize;
        }
		if (atoi (buffer) == frameNumber)
			break;
    }
	cout << "SUCCESS: CLIENT EXIT" <<endl;
    close(sockfd);
    return 0;
}

