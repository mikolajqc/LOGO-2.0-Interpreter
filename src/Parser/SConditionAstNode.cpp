#include "SConditionAstNode.h"

SConditionAstNode::SConditionAstNode(AstNode* parent)
:AstNode(parent)
{
}

float SConditionAstNode::calculate()
{
	if(children.size() == 1)
	{
		return children[0]->calculate();
	}
	else if(children.size() == 2)
	{
		if(children[0]->calculate() == 0 || children[1]->calculate() == 0) //check it!
		{
			return 0;
		}
	}
	return 1;
}

void SConditionAstNode::check()
{
}

void SConditionAstNode::execute(Executer* executer)
{
}
float SConditionAstNode::calc(Executer* executer)
{
	if(children.size() == 1)
	{
		return children[0]->calc(executer);
	}
	else if(children.size() == 2)
	{
		if(children[0]->calc(executer) == 0 || children[1]->calc(executer) == 0) //check it!
		{
			return 0;
		}
	}
	return 1;
}

