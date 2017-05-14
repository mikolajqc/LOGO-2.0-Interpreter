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

void MultOpAstNode::execute()
{
}

void MultOpAstNode::check()
{
}
