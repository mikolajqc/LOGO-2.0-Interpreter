#include "AddOpAstNode.h"

AddOpAstNode::AddOpAstNode(AstNode* parent)
:AstNode(parent)
{
}

void AddOpAstNode::setIsPlus(bool isPlus)
{
	this->isPlus = isPlus;
}

float AddOpAstNode::calculate()
{
	return isPlus;
}

void AddOpAstNode::execute(Executer* executer)
{
}

void AddOpAstNode::check()
{
}
float AddOpAstNode::calc(Executer* executer)
{
}

