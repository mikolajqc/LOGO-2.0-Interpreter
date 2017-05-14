#include "ExpAstNode.h"
#include <iostream>

ExpAstNode::ExpAstNode(AstNode* parent)
:AstNode(parent)
{
}

float ExpAstNode::calculate()
{
	//std::cout << "expcalculate\n";
	float result;
	
	if(children.size() == 1)
	{
		//std::cout << "ok\n";
		result = children[0]->calculate();
	}
	else
	{
		if(children[1]->calculate() == 1) //+
		{
			result = children[0]->calculate() + children[2]->calculate();
		}
		else //-
		{
			result = children[0]->calculate() - children[2]->calculate();
		}
	}
	
	return result;
}

void ExpAstNode::execute()
{
}
