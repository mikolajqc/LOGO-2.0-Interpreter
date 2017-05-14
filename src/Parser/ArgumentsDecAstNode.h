#ifndef ARGUMENTSDECASTNODE_H
#define ARGUMENTSDECASTNODE_H
#include "AstNode.h"
#include "string"

class ArgumentsDecAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	int getArgumentsNumber();
	void setArgumentName(std::string argumentName);
	
	ArgumentsDecAstNode(AstNode* parent);
	
private:
	std::string argumentName;
};

#endif // ARGUMENTSDECASTNODE_H
