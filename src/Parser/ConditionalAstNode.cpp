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

void ConditionalAstNode::execute(Executer* executer)
{
	std::cout << "ConditionalExecution\n";
	//float value = children[0]->calculate();
	
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

