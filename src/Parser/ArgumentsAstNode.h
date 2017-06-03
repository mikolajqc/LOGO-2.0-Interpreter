#ifndef ARGUMENTSASTNODE_H
#define ARGUMENTSASTNODE_H
#include "AstNode.h"
#include "string"

class ArgumentsAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	
	int GetArgumentsNumber();
	//void SetArgumentName(std::string argumentName);
	
	ArgumentsAstNode(AstNode* parent, Window*);
	
private:
	std::string argumentName;
};

#endif // ARGUMENTSASTNODE_H
