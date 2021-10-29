//Grade XI Project
//Guess The Word 2-Player Game

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void task (char ques[100], char hints[3][25], char word[30]);
void maingame (char ques[100], char hints[3][25], char word[30]);

int main () {
    char p1[20], p2[20], ques[100], hints[3][25], word[30], ask;

    system ("cls");
    cout <<"WELCOME TO 'GUESS THE WORD'\n";

    cout <<"\nEnter your First Name:\n";
    cout <<"Player 1: ";
    scanf (" %[^\n]s", p1);
    cout <<"Player 2: ";
    scanf (" %[^\n]s", p2);

    play:

    cout <<"\nFirstly, let "<<p1<<" make a question and add three hints...";
    cout <<"\n"<<p2<<", please close your eyes while "<<p1<<" sets his questions."<<endl;
    sleep(5);

    system ("cls");
    task (ques, hints, word);
    system ("cls");
    maingame (ques, hints, word);
    system ("cls");

    cout <<"\nIt's your turn now, "<<p2;
    cout <<"\n"<<p1<<", close your eyes.\n";
    sleep(2);
    system ("cls");
    task (ques, hints, word);
    system ("cls");
    maingame (ques, hints, word);
    system ("cls");

    cout <<"Rematch? Y/N...\n> ";
    cin >> ask;
    ask = toupper (ask);
    if (ask == 'Y')
        goto play;
    else
        cout <<"Thank you for playing. Closing the program now.";
    sleep (2);
    exit(0);
    return 0;
}

void task (char ques[100], char hints[3][25], char word[30]) {
    cout <<"\nMake your question:\n";
    scanf (" %[^\n]s", ques);
    cout <<"Enter Hints:\n";
    cout <<"Hint 1: ";
    scanf (" %[^\n]s", hints[0]);
    cout <<"Hint 2: ";
    scanf (" %[^\n]s", hints[1]);
    cout <<"Hint 3: ";
    scanf (" %[^\n]s", hints[2]);
    cout <<"What was the word you thought of?\n> ";
    scanf (" %[^\n]s", word);
    cout <<"\nWell Done! Let your friend guess the word!\n";
    sleep (3);
}

void maingame (char ques[100], char hints[3][25], char word[30]) {
    char gusword [30];
    cout <<"Okay... Here's the question: \n";
    puts (ques);
    cout <<"\nGuess the Word\n";
    for (int i=0; i<=3; ++i) {
        cout <<"Guess "<<i+1<<": ";
        scanf (" %[^\n]s", gusword);
        if (strcmpi(gusword, word)) {
            if (i < 3) {
                if (i==0) cout <<"Wrong! Hint 1: ";
                else if (i==1) cout <<"Wrong Again! Hint 2: ";
                else if (i==2) cout <<"Final Hint: "; 
                puts (hints[i]);
            }
            else if (i==3) {
                cout <<"Looks like your friend put a difficult word!\n";
                cout <<"The correct word is "<<word;
                cout <<"\nHit Enter to continue...";
                getch ();
            }
            sleep (1);
        }
        else {
            cout <<"Congrats! You guessed it correctly!\nHit Enter to continue...";
            getch();
            break;
        }
    }
}
