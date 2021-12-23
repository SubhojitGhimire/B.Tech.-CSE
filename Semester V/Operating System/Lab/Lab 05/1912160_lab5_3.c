// Q.3. Write a c program to simulate Shortest Remaining Time First (SRTF) algorithm.

#include <stdio.h>
#include <stdlib.h>

int main () {

    int arrivalTime[20], burstTime[20], temp[20], totalProcess, waitTime[20], turnaroundTime[20];
    int endTime, smallest, count = 0, time;
    float avgWaitTime=0, avgTurnaroundTime=0;
    int ii, jj;

    system ("cls");

    printf ("ENTER NUMBER OF PROCESSES: ");
    scanf ("%d", &totalProcess); 

    printf("\nENTER PROCESS DETAILS\n");
    for (ii=0; ii < totalProcess; ++ii) {
        printf ("\nARRIVAL TIME OF P%d : ", ii + 1);
        scanf ("%d", &arrivalTime [ii]);
        printf ("BURST TIME OF P%d : ", ii + 1);
        scanf ("%d", &burstTime [ii]);
        temp [ii] = burstTime [ii];
    }

    temp [19] = 9999;
  
    for (time=0; count != totalProcess; ++time) {
        smallest = 19;
        for (ii=0; ii < totalProcess; ++ii) {
            if (arrivalTime [ii] <= time && temp [ii] < temp [smallest] && temp [ii] > 0)
                smallest = ii;
        }
        --temp [smallest];
        if (temp [smallest] == 0) {
            ++count;
            endTime = time + 1;
            waitTime [smallest] = endTime - arrivalTime [smallest] - burstTime [smallest];
            avgWaitTime = avgWaitTime + endTime - arrivalTime [smallest] - burstTime [smallest];
            avgTurnaroundTime = avgTurnaroundTime + endTime - arrivalTime [smallest];
        }
    }

    printf ("\nPROCESS NO. \t ARRIVAL TIME \t BURST TIME \t WAITING TIME \t TURNAROUND TIME");
    for (ii=0; ii < totalProcess; ++ii) {
        turnaroundTime [ii] = burstTime [ii] + waitTime [ii];
        printf ("\nP%d \t\t %d \t\t %d \t\t %d \t\t %d", ii+1, arrivalTime[ii], burstTime[ii], waitTime[ii], turnaroundTime[ii]);
    }

    avgWaitTime /= totalProcess;
    avgTurnaroundTime /= totalProcess;
    printf ("\n\nAVERAGE WAITING TIME = %0.3f\n", avgWaitTime);
    printf ("Average Turnaround time = %0.3f\n\n", avgTurnaroundTime);

    system ("pause");
    return 0;
}