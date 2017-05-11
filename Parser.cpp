#include "Parser.h"

Parser::Parser()
{
	lexer = new Lexer(text.txt);
}

Parser::~Parser()
{
	delete lexer;
}