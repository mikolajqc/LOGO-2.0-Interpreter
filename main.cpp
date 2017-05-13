#include <stdio.h>
//#include "Lexer.h"
#include "Parser.h"
#include "ValAstNode.h"

int main(int argc, char **argv)
{
	Parser parser;
	parser.start();
	
	ValAstNode val(nullptr);
	val.SetValue("10.123");
	
	return 0;
	
	/*
	Lexer lex("test.txt");
	Lexeme currentLexeme = lex.NextLexeme();
	int i = 0;
	while(currentLexeme.GetCategory() != EMPTY && i < 50)
	{
		currentLexeme = lex.NextLexeme();
		++i;
	}
	*/
	
	return 0;
}
