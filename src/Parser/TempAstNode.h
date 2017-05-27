#ifndef TEMPASTNODE_H
#define TEMPASTNODE_H
#include "AstNode.h"

class TempAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void execute(Executer* executer);
	void check();
	
	TempAstNode(AstNode* parent);
	
	void SetOperation(std::string operation);
	std::string GetOperation();

private:
	std::string operation;

};


#endif // TEMPASTNODE_H
