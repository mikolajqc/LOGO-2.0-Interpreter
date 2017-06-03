#include "TempAstNode.h"
#include <iostream>

TempAstNode::TempAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
	
}

float TempAstNode::calculate()
{
	return 1;
}

void TempAstNode::execute(Executer* executer)
{
	if(operation == "FD")
	{
		window->addOperation(std::pair<int, int>(0,children[0]->calc(executer)));
	}
	else if(operation == "BK")
	{
		window->addOperation(std::pair<int, int>(1,children[0]->calc(executer)));
	}
	else if(operation == "RT")
	{
		window->addOperation(std::pair<int, int>(2,children[0]->calc(executer)));
	}
	else if(operation == "LT")
	{
		window->addOperation(std::pair<int, int>(3,children[0]->calc(executer))); 
	}
	else if(operation == "PU")
	{
		window->addOperation(std::pair<int, int>(4,0));
	}
	else if(operation == "PD")
	{
		window->addOperation(std::pair<int, int>(5,0));
	}
	else if(operation == "CS")
	{
		window->addOperation(std::pair<int, int>(9,0));
	}
	else if (operation == "SETPC")
	{ 
		window->addOperation(std::pair<int, int>(6,children[0]->calc(executer)));
		window->addOperation(std::pair<int, int>(7,children[1]->calc(executer)));
		window->addOperation(std::pair<int, int>(8,children[2]->calc(executer)));
	}
	
}

void TempAstNode::check()
{
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		std::cout <<"Value: "  << children[i]->calculate() << "\n";
	}
}
float TempAstNode::calc(Executer* executer)
{
	return 1;
}

void TempAstNode::SetOperation(std::string operation)
{
	this->operation = operation;
}

std::string TempAstNode::GetOperation()
{
	return operation;
}


