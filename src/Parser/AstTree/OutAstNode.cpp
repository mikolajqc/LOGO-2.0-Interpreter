#include "OutAstNode.h"
#include <iostream>

OutAstNode::OutAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
	
}

float OutAstNode::calculate()
{
	return -1;
}

void OutAstNode::execute(Executer* executer)
{
	calc(executer);
}

void OutAstNode::check()
{
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		std::cout <<"Value: "  << children[i]->calculate() << "\n";
	}
}
float OutAstNode::calc(Executer* executer)
{
	if(operation == "OUTPUT")
	{
		executer->SetReturnValue(children[0]->calc(executer));
	}
	else if (operation == "PRINT")
	{
		std::cout <<  "PRINT: " <<children[0]->calc(executer) << "\n"; //zrob osobna funkcje print()
	}
	else if(operation == "STOP")
	{
		executer->SetReturnValue(0);
	}
	
	return 1;
}

void OutAstNode::SetOperation(std::string operation)
{
	this->operation = operation;
}

std::string OutAstNode::GetOperation()
{
	return operation;
}
