#ifndef CONDITIONASTNODE_H
#define CONDITIONASTNODE_H
#include "AstNode.h"

class ConditionAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	ConditionAstNode(AstNode* parent);
private:
};

#endif // CONDITIONASTNODE_H
