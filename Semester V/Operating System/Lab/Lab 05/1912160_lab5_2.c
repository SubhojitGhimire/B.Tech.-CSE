// Q.2. Write a c program to simulate the SJF (Shortest Job First) algorithm.

#include <stdio.h>
#include <stdlib.h>

int main () {

    int burstTime[20], process[20], waitTime[20], turnAroundTime[20], totalProcess, total=0, pos, temp;
    float avg_waitTime, avg_turnAroundTime;
    int ii, jj;

    system ("cls");

    printf ("ENTER NUMBER OF PROCESSES: ");
    scanf ("%d", &totalProcess);
  
    printf ("\nENTER BURST TIME FOR PROCESS \n");
    for (ii=0; ii < totalProcess; ++ii) {
        printf ("P%d : ", ii + 1);
        scanf ("%d", &burstTime [ii]);
        process [ii] = ii + 1;         
    }
  
   //SORTING BURST TIMES
    for (ii=0; ii < totalProcess; ++ii) {
        pos = ii;
        for (jj=ii+1; jj < totalProcess; jj++) {
            if (burstTime [jj] < burstTime [pos])
                pos = jj;
        }
  
        temp = burstTime [ii];
        burstTime [ii] = burstTime [pos];
        burstTime [pos] = temp;
  
        temp = process [ii];
        process [ii] = process [pos];
        process [pos] = temp;
    }
   
    waitTime [0] = 0;            
    for (ii=1; ii < totalProcess; ii++) {
        waitTime [ii] = 0;
        for (jj=0; jj < ii; ++jj)
            waitTime [ii] += burstTime [jj];
        total += waitTime [ii];
    }
  
    avg_waitTime = (float) total / totalProcess;      
    total = 0;
  
    printf ("\nPROCESS NO. \t BURST TIME \t WAITING TIME \t TURNAROUND TIME");
    for (ii=0; ii < totalProcess; ++ii) {
        turnAroundTime [ii] = burstTime [ii] + waitTime [ii];   
        total += turnAroundTime [ii];
        printf ("\nP%d \t\t %d \t\t %d \t\t %d", process[ii], burstTime[ii], waitTime[ii], turnAroundTime[ii]);
    }
  
    avg_turnAroundTime = (float) total / totalProcess;    
    printf ("\n\nAVERAGE WAITING TIME = %0.3f", avg_waitTime);
    printf ("\nAVERAGE TURNAROUND TIME = %0.3f\n", avg_turnAroundTime);

    system ("pause");
}