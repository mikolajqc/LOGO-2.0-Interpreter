#ifndef CONDITIONALASTNODE_H
#define CONDITIONALASTNODE_H
#include "AstNode.h"


class ConditionalAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	ConditionalAstNode(AstNode* parent, Window*);
private:
	bool condition; // int z exp castowalny na boola
};

#endif // CONDITIONALASTNODE_H
