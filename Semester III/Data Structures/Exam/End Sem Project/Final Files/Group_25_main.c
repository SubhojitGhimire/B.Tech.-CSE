/*        
GROUP 25
LINKED LIST (SINGLY, DOUBLY, CIRCULAR)
Members List:
1. Rahul Gautam Singh (1912082)
2. Ashish Upadhyaya (1912132)
3. Prottay Kumar Adhikary (1912157)
4. Saurabh Sinha (1912159)
5. Subhojit Ghimire (1912160)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "Group_25_header.h"

int main()
{
    char option ['!'];
    do
    {
        system ("cls");
        printf ("\n####################################\n");
        printf ("########### MUSiC PLAYER ###########\n");
        printf ("####################################\n");
        printf ("\nContinue? Y/N...\n> ");
        scanf ("%s", &option);
        if (option [0] == 'y' || option [0] == 'Y')
        {
            system ("cls");
            main_menu ();
        }
    }while (option [0] == 'y' || option [0] == 'Y');
    return 0;  
}