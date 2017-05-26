#include <stdio.h>
#include "Parser.h"
#include "ValAstNode.h"
//#include "src/Executer/Executer.h"

int main(int argc, char **argv)
{
	Parser parser;
	
	parser.start();
	parser.check();
	parser.execute();
	
	return 0;
}
