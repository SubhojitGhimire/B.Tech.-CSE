%{
	#include<stdio.h>
%}

%%
[a-zA-Z] {printf("<ALPHABET RECOGNISED> ");}
[^a-zA-Z\n] {printf("<NOT AN ALPHABET> ");}
%%

int yywrap(){
	return 1;
}

main(){
	printf ("ENTER A CHARACTER: \n");
	yylex();
}