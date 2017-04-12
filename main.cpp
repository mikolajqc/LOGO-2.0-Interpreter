#include <stdio.h>
#include "Lexer.h"

int main(int argc, char **argv)
{
	
	Lexer lex("test.txt");
	Lexeme currentLexeme = lex.NextLexeme();
	while(currentLexeme.GetCategory() != EMPTY)
	{
		std::cout << currentLexeme.GetCategory() << " " << currentLexeme.GetValue() << std::endl;
		currentLexeme = lex.NextLexeme();
	}
	return 0;
}
