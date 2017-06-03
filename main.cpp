#include <stdio.h>
#include "Parser.h"
#include "ValAstNode.h"

int main(int argc, char **argv)
{
	Parser parser;
	
	parser.start();
	parser.check();
	parser.execute();
	
	return 0;
}
