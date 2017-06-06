#ifndef ARGUMENTSDECASTNODE_H
#define ARGUMENTSDECASTNODE_H
#include "AstNode.h"
#include "string"

class ArgumentsDecAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	int getArgumentsNumber();
	void setArgumentName(std::string argumentName);
	std::string GetArgumentName();
	
	ArgumentsDecAstNode(AstNode* parent, Window*);
	
private:
	std::string argumentName;
};

#endif // ARGUMENTSDECASTNODE_H
