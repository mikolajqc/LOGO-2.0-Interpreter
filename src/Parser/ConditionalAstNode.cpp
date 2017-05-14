#include "ConditionalAstNode.h"
#include <iostream>

ConditionalAstNode::ConditionalAstNode(AstNode* parent)
:AstNode(parent)
{
}
float ConditionalAstNode::calculate()
{
	return 0;
}

void ConditionalAstNode::check()
{
	//condition = children[0]->calculate();
	
	std::cout << "Condition = " << children[0]->calculate();
	
	children[1]->check();
}

void ConditionalAstNode::execute()
{
}

