#ifndef EXECUTER_H
#define EXECUTER_H

#include <vector>
#include "Parser.h"
#include "StackOfContext.h"

class Executer
{
public:
	Executer();
	~Executer();
	
	void execute();

private:
	Parser* parser;
	
	StackOfContext stackOfContexts;
	
	std::map<std::string, AstNode*> procedures;
};

#endif // EXECUTER_H
