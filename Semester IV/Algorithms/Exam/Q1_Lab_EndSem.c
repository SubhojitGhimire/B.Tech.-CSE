#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main () {
    char input[100];
    //printf ("Input: ");
    scanf (" %[^\n]", input);

    char reverse[strlen(input)-1];
    for (int i=0, j=strlen(input)-1; i<strlen(input); ++i, --j) {
        reverse[j] = input[i];
    }
    reverse[strlen(input)] = '\0';

    char output[strlen(input)];
    char temp['!'];
    int i=0, j=0, k=0;
    for (i; i<=strlen(input); ++i) {
        if (isalpha(reverse[i])) {
            temp [j++] = reverse[i];
        }
        else {
            --j;
            while (j>=0) {
                output [k++] = temp [j--];
            }
            output [k++] = ' ';
            j = 0;
        }
    }
    output[--k] = '\0';

    //printf ("Output: ");
    printf ("%s", output);
    return 0;
}