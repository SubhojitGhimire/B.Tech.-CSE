/*
Q.1. Write a C program using threads that, one to increment the value of a shared variable and second to decrement the value of the shared variable. Both the threads make use of semaphore variable so that only one of the threads is executing in its critical section.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int sharedVar, preemptionFlag = 0;
sem_t semaphoreVar;

void *increment () {
	int threadInc;
	sem_wait (&semaphoreVar);
	threadInc = sharedVar;
	printf ("\nTHREAD READS IN VALUE: %d\n", threadInc);
	++threadInc;
	printf ("UPDATED VALUE IN THREAD: %d\n", threadInc);
	printf ("PREEMPTING...\n");
	++preemptionFlag;
	int preFlag = preemptionFlag;
	sleep (1);
	if (preFlag == preemptionFlag)
		printf ("PREEMPTION FAILED: CRITICAL SECTION NOT EMPTY. ALREADY A THREAD RUNNING IN CRITICAL SECTION\n");
	--preemptionFlag;
	sharedVar = threadInc;
	printf ("THREAD UPDATED THE SHARED VALUE: %d\n", sharedVar);    
	sem_post (&semaphoreVar);
}

void *decrement () {
	int threadDec;
	sem_wait (&semaphoreVar);
	threadDec = sharedVar;
	printf ("\nTHREAD READS IN VALUE: %d\n", threadDec);
	--threadDec;
	printf ("UPDATED VALUE IN THREAD: %d\n", threadDec);
	printf ("PREEMPTING...\n");
	++preemptionFlag;
	int preFlag = preemptionFlag;
	sleep (1);
	if (preFlag == preemptionFlag)
		printf ("PREEMPTION FAILED: CRITICAL SECTION NOT EMPTY. ALREADY A THREAD RUNNING IN CRITICAL SECTION\n");
	--preemptionFlag;
	sharedVar = threadDec;
	printf ("THREAD UPDATED THE SHARED VALUE: %d\n", sharedVar);
	sem_post (&semaphoreVar);
}



int main () {
	printf ("ENTER SHARED VALUE: ");
	scanf ("%d", &sharedVar);
	sem_init (&semaphoreVar, 0, 1);
	pthread_t thread_1, thread_2;
	pthread_create (&thread_1, NULL, increment, NULL);
	pthread_create (&thread_2, NULL, decrement, NULL);
	pthread_join (thread_1, NULL);
	pthread_join (thread_2,NULL);
	printf ("\nFINAL VALUE OF SHARED VARIBALE: %d\n", sharedVar);
}