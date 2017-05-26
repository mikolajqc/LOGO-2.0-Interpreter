#ifndef EXECUTER_H
#define EXECUTER_H

#include "Parser.h"

class Executer
{
public:
	Executer();
	~Executer();
	
	void execute();

private:
	Parser* parser;

};

#endif // EXECUTER_H
