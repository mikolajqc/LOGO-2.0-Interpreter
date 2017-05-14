#ifndef TCONDITIONASTNODE_H
#define TCONDITIONASTNODE_H
#include "AstNode.h"

class TConditionAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	TConditionAstNode(AstNode* parent);
private:
};

#endif // TCONDITIONASTNODE_H
