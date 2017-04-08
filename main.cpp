#include <stdio.h>
#include "Lexer.h"

int main(int argc, char **argv)
{
	
	Lexer lex("test.txt");
	lex.NextLexeme();
	return 0;
}
