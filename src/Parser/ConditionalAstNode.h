#ifndef CONDITIONALASTNODE_H
#define CONDITIONALASTNODE_H
#include "AstNode.h"


class ConditionalAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	ConditionalAstNode(AstNode* parent);
private:
	bool condition; // int z exp castowalny na boola
};

#endif // CONDITIONALASTNODE_H
