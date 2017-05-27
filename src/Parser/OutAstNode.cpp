#include "OutAstNode.h"
#include <iostream>

OutAstNode::OutAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

float OutAstNode::calculate()
{
	return -1;
}

void OutAstNode::execute(Executer* executer)
{
	
}

void OutAstNode::check()
{
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		std::cout <<"Value: "  << children[i]->calculate() << "\n";
	}
}
float OutAstNode::calc(Executer* executer)
{
	return 0;
}

