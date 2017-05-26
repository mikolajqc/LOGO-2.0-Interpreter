#include <stdio.h>
#include "Parser.h"
#include "ValAstNode.h"
#include "src/Executer/Executer.h"

int main(int argc, char **argv)
{
	Executer executer;
	executer.execute();
	
	return 0;
}
