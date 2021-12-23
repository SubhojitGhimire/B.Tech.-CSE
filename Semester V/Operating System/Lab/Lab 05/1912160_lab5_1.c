// Q.1. Write a c program to simulate First Come First Serve (FCFS) algorithm.

#include <stdio.h>
#include <stdlib.h>

int main () {

    int totalProcess, burstTime [20], waitTime [20], turnaroundTime[20];
    float avgWaitTime=0, avgTurnaroundTime=0;
    int ii, jj;
    
    system ("cls");

    printf ("ENTER NUMBER OF PROCESSES: ");
    scanf ("%d", &totalProcess);
 
    printf ("\nENTER BURST TIME FOR PROCESS \n");
    for (ii=0; ii < totalProcess; ++ii) {
        printf ("P%d : ", ii + 1);
        scanf ("%d", &burstTime [ii]);
    }
 
    waitTime [0] = 0;   
    for(ii=1; ii < totalProcess; ++ii) {
        waitTime [ii] = 0;
        for (jj=0; jj < ii; ++jj)
            waitTime [ii] += burstTime [jj];
    }
 
    printf ("\nPROCESS NO. \t BURST TIME \t WAITING TIME \t TURNAROUND TIME");
    for (ii=0; ii < totalProcess; ++ii) {
        turnaroundTime [ii] = burstTime [ii] + waitTime [ii];
        avgWaitTime += waitTime [ii];
        avgTurnaroundTime += turnaroundTime [ii];
        printf ("\nP%d \t\t %d \t\t %d \t\t %d", ii+1, burstTime[ii], waitTime[ii], turnaroundTime[ii]);
    }
 
    avgWaitTime /= ii;
    avgTurnaroundTime /= ii;
    printf ("\n\nAVERAGE WAITING TIME = %0.3f", avgWaitTime);
    printf ("\nAVERAGE TURNAROUND TIME = %0.3f\n\n", avgTurnaroundTime);

    system ("pause");
    return 0;
}