#include "TempAstNode.h"
#include <iostream>

TempAstNode::TempAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

float TempAstNode::calculate()
{
	return -1;
}

void TempAstNode::execute(Executer* executer)
{
	
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


