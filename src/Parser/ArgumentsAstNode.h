#ifndef ARGUMENTSASTNODE_H
#define ARGUMENTSASTNODE_H
#include "AstNode.h"
#include "string"

class ArgumentsAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	
	int GetArgumentsNumber();
	//void SetArgumentName(std::string argumentName);
	
	ArgumentsAstNode(AstNode* parent);
	
private:
	std::string argumentName;
};

#endif // ARGUMENTSASTNODE_H
