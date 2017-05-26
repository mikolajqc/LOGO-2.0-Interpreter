#include "ExpAstNode.h"
#include <iostream>

ExpAstNode::ExpAstNode(AstNode* parent)
:AstNode(parent)
{
}

float ExpAstNode::calculate()
{
	float result;

	result = children[0]->calculate();
	
	if(children.size() > 1)
	{
		for(unsigned int i = 0; i < children.size()/2; ++i)
		{
			if(children[2*i + 1]->calculate() == 1)
			{
				result += children[2*i + 2]->calculate();
			}
			else
			{
				result -= children[2*i + 2]->calculate();
			}
		}
		
	}
	
	return result;
}

void ExpAstNode::execute(Executer* executer)
{
}

void ExpAstNode::check()
{
}
float ExpAstNode::calc(Executer* executer)
{
}

