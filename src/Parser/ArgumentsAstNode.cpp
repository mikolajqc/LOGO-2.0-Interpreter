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
	
	for(size_t i = 0; i < children.size(); ++i)
	{
		children[i]->calculate();
	}
	
	/*if(children.size() == 2)
	{
		std::cout << children[0]->calculate() << " < value of arg\n";
		children[1]->check(); //arguments
	}
	else if(children.size() == 1)
	{
		std::cout << children[0]->calculate() << " < value of arg\n";
	}
	*/
}

void ArgumentsAstNode::execute(Executer* executer)
{
	std::cout << "ArgumentsAstNode executing\n";
	children[0]->calc(executer);
	if(children.size() > 1)children[1]->execute(executer);
}

int ArgumentsAstNode::GetArgumentsNumber()
{
	//if(this->children.size() > 1)
	//{
		//return 1 + (dynamic_cast<ArgumentsAstNode*>(children[1]))->GetArgumentsNumber();
	//}
	
	return 2;
}
float ArgumentsAstNode::calc(Executer* executer)
{
	return 0;
}

