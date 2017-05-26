#ifndef CONDITIONASTNODE_H
#define CONDITIONASTNODE_H
#include "AstNode.h"

class ConditionAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	ConditionAstNode(AstNode* parent);
private:
};

#endif // CONDITIONASTNODE_H
