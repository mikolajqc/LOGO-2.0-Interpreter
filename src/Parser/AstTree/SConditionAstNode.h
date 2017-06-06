#ifndef SCONDITIONASTNODE_H
#define SCONDITIONASTNODE_H
#include "AstNode.h"

class SConditionAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	SConditionAstNode(AstNode* parent, Window*);
};

#endif // SCONDITIONASTNODE_H
