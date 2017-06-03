#include "ConditionalAstNode.h"
#include <iostream>

ConditionalAstNode::ConditionalAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
}
float ConditionalAstNode::calculate()
{
	return 0;
}

void ConditionalAstNode::check()
{
	std::cout << "Condition = " << children[0]->calculate();
	children[1]->check();
}

void ConditionalAstNode::execute(Executer* executer)
{
	std::cout << "ConditionalExecution\n";
	
	float value = children[0]->calc(executer);
	
	if(value)
	{
		std::cout << "Condition is true\n";
		executer->AddContext();
		children[1]->execute(executer);
		executer->DeleteContext();
	}
	
}
float ConditionalAstNode::calc(Executer* executer)
{
	return 0;
}

