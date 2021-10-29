#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main () {
    char input ['!'], operation ['!'];
    int OperationCounter = 0, InputCounter = 0;

    //printf ("Enter Infix Expression: ");
    scanf (" %[^\n]%*c", input);

    //printf ("Output Postfix Expression: ");
    operation[OperationCounter++] = '(';
    strcat (input, ")");

    while (OperationCounter != 0) {
        if (isalpha (input[InputCounter]))
            printf ("%c", input[InputCounter]);
        else if (input[InputCounter] == '(')
            operation[OperationCounter++] = '(';
        else if (input[InputCounter] == ')') {
            --OperationCounter;
            while (operation[OperationCounter] != '(')
                printf ("%c", operation[OperationCounter--]);
        }
        else {
            int PEDMASkey[2];
            operation[OperationCounter] = input[InputCounter];
            do {
                for (int i=0; i<2; ++i) {
                    switch (operation[OperationCounter - i]) {
                        case '^' : PEDMASkey[i] = 3; break;
                        case '/' : PEDMASkey[i] = 2; break;
                        case '*' : PEDMASkey[i] = 2; break;
                        case '+' : PEDMASkey[i] = 1; break;
                        case '-' : PEDMASkey[i] = 1; break;
                        default: PEDMASkey[i] = 0; break;
                    }
                }
                if (PEDMASkey[1] >= PEDMASkey [0] && (PEDMASkey[1] != 3 || PEDMASkey[0] != 3)) {
                    printf ("%c", operation[OperationCounter - 1]);
                    operation[OperationCounter - 1] = operation[OperationCounter];
                    --OperationCounter;
                }
                else break;
            } while (OperationCounter);
            ++OperationCounter;
        }
        ++InputCounter;
    } 
    return 0;
}