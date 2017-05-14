#include <stdio.h>
//#include "Lexer.h"
#include "Parser.h"
#include "ValAstNode.h"

int main(int argc, char **argv)
{
	Parser parser;
	parser.start();
	
	parser.execute();
	
	
	return 0;
}
