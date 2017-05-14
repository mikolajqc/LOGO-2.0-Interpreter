#ifndef SCONDITIONASTNODE_H
#define SCONDITIONASTNODE_H
#include "AstNode.h"

class SConditionAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	SConditionAstNode(AstNode* parent);
};

#endif // SCONDITIONASTNODE_H
