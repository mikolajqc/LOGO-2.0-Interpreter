#include "SExpAstNode.h"
#include <iostream>

SExpAstNode::SExpAstNode(AstNode* parent)
:AstNode(parent)
{
}

float SExpAstNode::calculate()
{
	float result;

	result = children[0]->calculate();
	
	if(children.size() > 1) // zawsze 2i + 1 na nieparzystych operatory
	{
		for(unsigned int i = 0; i < children.size()/2; ++i)
		{
			if(children[2*i + 1]->calculate() == 1) //mnozenie
			{
				result *= children[2*i + 2]->calculate();
			}
			else
			{
				result /= children[2*i + 2]->calculate();
			}
		}
	}
	
	return result;
}

void SExpAstNode::execute()
{
}

void SExpAstNode::check()
{
}
