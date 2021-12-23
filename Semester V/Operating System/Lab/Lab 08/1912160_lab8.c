/*
 Q.1. Assume that a system has a 32-bit virtual address with a 4-KB page size. Write a C program that is passed a virtual address (in decimal) on the command line and have it output the page number and offset for the given address.
 */

#include <stdio.h>

#define pgNumberMask 0xFFFFF000
#define offsetMask 0x00000FFF

int main () {
	unsigned long address;
	int page, offset;

	printf ("ENTER ADDRESS: ");
	scanf ("%lu", &address);  // For example: 201529

	// Page Number =  quotient of  address / 4KB and offset = remainder
	page = (address & pgNumberMask) >> 12; // Page size is 4KB => 12 bits holding the virtual address
	offset = address & offsetMask;

	printf ("PAGE NUMBER: %d\n", page); // For address 201529, the page number is 49
	printf ("OFFSET: %d\n", offset); // For address 201529, the offset is 825

	return 0;
}