#include "MultOpAstNode.h"

MultOpAstNode::MultOpAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
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

