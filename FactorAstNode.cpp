#include "FactorAstNode.h"

FactorAstNode::FactorAstNode(AstNode* parent)
:AstNode(parent)
{
}

float FactorAstNode::calculate()
{
	return children[0]->calculate();
}

void FactorAstNode::execute()
{
}
