#ifndef TCONDITIONASTNODE_H
#define TCONDITIONASTNODE_H
#include "AstNode.h"

class TConditionAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	TConditionAstNode(AstNode* parent, Window*);
private:
};

#endif // TCONDITIONASTNODE_H
