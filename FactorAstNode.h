#ifndef FACTORASTNODE_H
#define FACTORASTNODE_H
#include "AstNode.h"

class FactorAstNode : public AstNode
{
public:
	FactorAstNode(AstNode* parent);

	float calculate();
	void execute();
	
};

#endif // FACTORASTNODE_H
