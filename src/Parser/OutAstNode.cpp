#include "OutAstNode.h"
#include <iostream>

OutAstNode::OutAstNode(AstNode* parent)
:AstNode(parent)
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
		//return 
		//output i stop bedzie zamienial flagi stopu w kontexcie. kazda operacja bedzie sprawdzac czy moze sie wykonywac
		//jak nie moze to koniec i zwraca, az bedzie mozna
	}
	else if (operation == "PRINT")
	{
		std::cout << children[0]->calc(executer); //zrob osobna funkcje print()
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
