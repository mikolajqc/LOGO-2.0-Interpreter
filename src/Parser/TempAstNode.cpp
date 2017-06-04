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
		window->addOperation(std::pair<int, double>(0,children[0]->calc(executer)));
	}
	else if(operation == "BK")
	{
		window->addOperation(std::pair<int, double>(1,children[0]->calc(executer)));
	}
	else if(operation == "RT")
	{
		window->addOperation(std::pair<int, double>(2,children[0]->calc(executer)));
	}
	else if(operation == "LT")
	{
		window->addOperation(std::pair<int, double>(3,children[0]->calc(executer))); 
	}
	else if(operation == "PU")
	{
		window->addOperation(std::pair<int, double>(4,0));
	}
	else if(operation == "PD")
	{
		window->addOperation(std::pair<int, double>(5,0));
	}
	else if(operation == "CS")
	{
		window->addOperation(std::pair<int, double>(9,0));
	}
	else if (operation == "SETPC")
	{ 
		window->addOperation(std::pair<int, double>(6,children[0]->calc(executer)));
		window->addOperation(std::pair<int, double>(7,children[1]->calc(executer)));
		window->addOperation(std::pair<int, double>(8,children[2]->calc(executer)));
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


