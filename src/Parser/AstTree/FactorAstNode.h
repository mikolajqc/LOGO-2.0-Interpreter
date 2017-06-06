#ifndef FACTORASTNODE_H
#define FACTORASTNODE_H
#include "AstNode.h"

class FactorAstNode : public AstNode
{
public:
float calc(Executer* executer);
	FactorAstNode(AstNode* parent, Window* window);

	float calculate();
	void execute(Executer* executer);
	void check();
	
};

#endif // FACTORASTNODE_H
