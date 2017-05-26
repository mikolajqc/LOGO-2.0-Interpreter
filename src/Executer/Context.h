#ifndef CONTEXT_H
#define CONTEXT_H
#include <map>
#include "AstNode.h"

class Context
{
public:
	Context();
	~Context();
	
	
	void AddLocalVariable(std::string name, float value);
	void AddArgument(std::string name, float value);
	bool GetVariable(std::string name, float& value);
	//table of symbols and procedures(only for main)
private:
	std::map<std::string, float> localVariables;
	std::map<std::string, float> arguments;
	
	bool GetLocalVariable(std::string name, float& value);
	bool GetArgument(std::string name, float& value);
	
};

#endif // CONTEXT_H
