#include <stdio.h>
#include "Parser.h"
#include "ValAstNode.h"

int main(int argc, char **argv)
{
	std::string path;
	if(argc==1)
	{
		path = "test.txt";
	}
	else
	{
		path = argv[1];
	}
	
	Parser parser(path);
	
	parser.start();
	parser.check();
	parser.execute();
	
	return 0;
}
