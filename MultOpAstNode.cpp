#include "MultOpAstNode.h"

MultOpAstNode::MultOpAstNode(AstNode* parent)
:AstNode(parent)
{
}

void MultOpAstNode::setIsMult(bool isMult)
{
	this->isMult = isMult;
}

float MultOpAstNode::calculate()
{
	return isMult;
}

void MultOpAstNode::execute(Executer* executer)
{
}

void MultOpAstNode::check()
{
}
float MultOpAstNode::calc(Executer* executer)
{
}

