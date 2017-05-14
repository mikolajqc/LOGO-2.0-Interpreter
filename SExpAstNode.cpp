#include "SExpAstNode.h"

SExpAstNode::SExpAstNode(AstNode* parent)
:AstNode(parent)
{
}

float SExpAstNode::calculate()
{
	float result;
	
	if(children.size() == 1)
	{
		result = children[0]->calculate();
	}
	else
	{
		if(children[1]->calculate() == 1) //mnozenie
		{
			result = children[0]->calculate() * children[2]->calculate();
		}
		else
		{
			result = children[0]->calculate() / children[2]->calculate();
		}
	}
	
	return result;
}

void SExpAstNode::execute()
{
}
