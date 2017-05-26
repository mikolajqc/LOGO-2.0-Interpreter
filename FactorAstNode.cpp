#include "FactorAstNode.h"

FactorAstNode::FactorAstNode(AstNode* parent)
:AstNode(parent)
{
}

float FactorAstNode::calculate()
{
	return children[0]->calculate();
}

void FactorAstNode::execute(Executer* executer)
{
}

void FactorAstNode::check()
{
}
float FactorAstNode::calc(Executer* executer)
{
	return children[0]->calc(executer);
}

