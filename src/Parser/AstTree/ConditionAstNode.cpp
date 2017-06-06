#include "ConditionAstNode.h"

ConditionAstNode::ConditionAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
}

float ConditionAstNode::calculate()
{
	if(children.size() == 1)
	{
		return children[0]->calculate();
	}
	else if(children.size() == 2)
	{
		if(children[0]->calculate() != 0 || children[1]->calculate() != 0)
		{
			return 1;
		}
	
	}
	
	return 0;
}

void ConditionAstNode::check()
{
}

void ConditionAstNode::execute(Executer* executer)
{
}
float ConditionAstNode::calc(Executer* executer)
{
	if(children.size() == 1)
	{
		return children[0]->calc(executer);
	}
	else if(children.size() == 2)
	{
		if(children[0]->calc(executer) != 0 || children[1]->calc(executer) != 0)
		{
			return 1;
		}
	
	}
	
	return 0;
}

