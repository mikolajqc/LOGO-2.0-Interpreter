#ifndef CONTEXT_H
#define CONTEXT_H
#include <map>
#include "AstNode.h"

class Context
{
public:
	Context();
	~Context();

	//table of symbols and procedures(only for main)
	
	std::map<std::string, float> localVariables;
	std::map<std::string, float> arguments;
	
	
};

#endif // CONTEXT_H
