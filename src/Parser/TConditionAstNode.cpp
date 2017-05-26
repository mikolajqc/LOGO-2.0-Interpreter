#include "TConditionAstNode.h"

TConditionAstNode::TConditionAstNode(AstNode* parent)
:AstNode(parent)
{
}

float TConditionAstNode::calculate()
{
	return children[0]->calculate();
}

void TConditionAstNode::check()
{
}

void TConditionAstNode::execute(Executer* executer)
{
}
float TConditionAstNode::calc(Executer* executer)
{
	return children[0]->calc(executer);
}

