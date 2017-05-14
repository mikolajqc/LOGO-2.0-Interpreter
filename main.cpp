#include <stdio.h>
//#include "Lexer.h"
#include "Parser.h"
#include "ValAstNode.h"

int main(int argc, char **argv)
{
	Parser parser;
	parser.start();
	
	parser.check();
	
	
	return 0;
}
