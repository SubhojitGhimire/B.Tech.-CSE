/*
Q.1. Write an algorithm for the Banker’s algorithm and implement it in C programming.
*/

#include <stdio.h>
#include <stdlib.h>

int display (int mm, int nn, int matrix [mm][nn]) {
	printf ("\t\t");
	for (int jj=0; jj<nn; ++jj)
		printf ("RESOURCE %d\t", jj+1);
	printf ("\n");
	
	for (int ii=0; ii<mm; ++ii) {
		printf ("PROCESS %d\t", ii+1);
		for (int jj=0; jj<nn; ++jj) {
			printf ("%d\t\t", matrix [ii][jj]);
		}
		printf ("\n");
	}
	printf ("\n");
	return 0;
}

int safeSequence (int mm, int nn, int need [mm][nn], int alloc [mm][nn], int avail [nn]) {
	int ff [mm], safeSeq [mm], ind = 0;
	for (int ii=0; ii<mm; ++ii)
		ff [ii] = 0;
	
	for (int ii=0; ii<mm; ++ii) {
		for (int jj=0; jj<mm; ++jj) {
			if (ff [jj] == 0) {
				int flag = 0;
				for (int kk=0; kk<nn; ++kk) {
					if (need [jj][kk] > avail [kk]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					safeSeq [ind++] = jj;
					for (int kk=0; kk<nn; ++kk)
						avail [kk] += alloc [jj][kk];
					ff [jj] = 1;
				}
			}
		}
	}
	
	printf ("A SAFE SEQUENCE HAS BEEN IDENTIFIED: ");
	for (int ii=0; ii<mm; ++ii)
		printf ("P%d -> ", safeSeq [ii]);
	printf ("end\n");
	
	return 0;
}	

int main () {
	int process, resource;
	printf ("ENTER TOTAL NUMBER OF PROCESSES: ");
	scanf ("%d", &process);
	printf ("ENTER TOTAL NUMBER OF RESOURCES: ");
	scanf ("%d", &resource);
	
	int availResource [resource];
	printf ("\nENTER AVAILABLE RESOURCES\n");
	for (int ii=0; ii<resource; ++ii) {
		printf ("RESOURCE %d: ", ii+1);
		scanf ("%d", &availResource [ii]);
	}
	
	int allocation [process][resource];
	for (int ii=0; ii<process; ++ii) {
		printf ("\nENTER ALLOCATION FOR PROCESS %d\n", ii+1);
		for (int jj=0; jj<resource; ++jj) {
			printf ("RESOURCE %d: ", jj+1);
			scanf ("%d", &allocation [ii][jj]);
		}
	}
	
	int maximum [process][resource];
	for (int ii=0; ii<process; ++ii) {
		printf ("\nENTER MAXIMUM FOR PROCESS %d\n", ii+1);
		for (int jj=0; jj<resource; ++jj) {
			printf ("RESOURCE %d: ", jj+1);
			scanf ("%d", &maximum [ii][jj]);
		}
	}
	
	int need [process][resource];
	for (int ii=0; ii<process; ++ii)
		for (int jj=0; jj<resource; ++jj)
			need [ii][jj] = maximum [ii][jj] - allocation [ii][jj];
		
	system ("clear");	
	
	printf ("ALLOCATION MATRIX\n");
	display (process, resource, allocation);
	printf ("MAXIMUM REQUIREMENT MATRIX\n");
	display (process, resource, maximum);
	printf ("NEED MATRIX\n");
	display (process, resource, need);
	
	safeSequence (process, resource, need, allocation, availResource);
	
	return 0;
}