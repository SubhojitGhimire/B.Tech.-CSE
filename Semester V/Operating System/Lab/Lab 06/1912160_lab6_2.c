/*
Q.2. Write a C program to simulate producer-consumer problem using semaphores. Create buffers for both producer and consumers. The producer should generate tasks and fill up the buffers and the consumer should consume and free up the buffer. Exit the process when the buffer is emptied.
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int itemNumber = 0, bufferSize = 0;
sem_t empty, full, mutex;

void producer () {
	sem_wait (&mutex);
	sem_post (&full);
	sem_wait (&empty);
	++itemNumber;
	printf ("ITEM %d PRODUCED\n", itemNumber);
	sem_post (&mutex);
}

void consumer () {
	sem_wait (&mutex);
	sem_wait (&full);
	sem_post (&empty);
	printf ("ITEM %d CONSUMED\n", itemNumber);
	--itemNumber;
	sem_post (&mutex);
}
 
int main () {
	while (bufferSize == 0) {
		printf ("ENTER BUFFER SIZE: ");
		scanf ("%d", &bufferSize);
	}
	
	sem_init (&empty, 0, bufferSize);
    sem_init (&full, 0, 0);
	sem_init (&mutex, 0, 1);
	
	int choice;
	int mutexVal, emptyVal, fullVal;
	
	printf ("######################\n");
	printf ("######## MENU ########\n");
	printf ("######################\n");
	printf ("0. EXIT\n");
	printf ("1. PRODUCER\n");
	printf ("2. CONSUMER\n");
	printf ("######################\n");
	printf ("\nMAKE YOUR SELECTION\n");
	while (choice != 0) {
		printf ("\n> ");
		scanf ("%d", &choice);
		switch (choice) {
			case 1:	sem_getvalue (&mutex, &mutexVal);
					sem_getvalue (&empty, &emptyVal);
					if ((mutexVal==1) && (emptyVal!=0))
						producer();
					else
						printf("BUFFER OVERFLOW...\n");
					break;
			case 2:	sem_getvalue (&mutex, &mutexVal);
					sem_getvalue (&full, &fullVal);
					if ((mutexVal==1) && (fullVal!=0))
						consumer();
					else
						printf ("BUFFER UNDERFLOW...\n");
					break;
			default:	printf ("ERROR: INVALID SELECTION.\n");
						break;
		}
	}  
	return 0;
}