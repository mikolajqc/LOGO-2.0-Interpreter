#include "ArgumentsAstNode.h"
#include <iostream>

ArgumentsAstNode::ArgumentsAstNode(AstNode* parent)
:AstNode(parent)
{
}


float ArgumentsAstNode::calculate()
{
	return 0;
}

void ArgumentsAstNode::check()
{
	std::cout << "checking Arguments\n";
	if(children.size() == 2)
	{
		std::cout << children[0]->calculate() << " < value of arg\n";
		children[1]->check(); //arguments
	}
	else if(children.size() == 1)
	{
		std::cout << children[0]->calculate() << " < value of arg\n";
	}
}

void ArgumentsAstNode::execute()
{
}

int ArgumentsAstNode::GetArgumentsNumber()
{
	return 0;
}