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
		std::cout <<"zolw do gory o: " <<children[0]->calc(executer) << "\n"; 
		window->addOperation(std::pair<int, int>(0,children[0]->calc(executer)));
	}
	else if(operation == "BK")
	{
		std::cout <<"zolw w dol o: " <<children[0]->calc(executer) << "\n"; 
		window->addOperation(std::pair<int, int>(1,children[0]->calc(executer)));
	}
	else if(operation == "RT")
	{
		std::cout <<"zolw w prawo o: " <<children[0]->calc(executer) << "\n";
		window->addOperation(std::pair<int, int>(2,children[0]->calc(executer)));
	}
	else if(operation == "LT")
	{
		std::cout <<"zolw w lewo o: " <<children[0]->calc(executer) << "\n";
		window->addOperation(std::pair<int, int>(3,children[0]->calc(executer))); 
	}
	else if(operation == "PU")
	{
		std::cout <<"podnies zolwia! \n";
		window->addOperation(std::pair<int, int>(4,0));
	}
	else if(operation == "PD")
	{
		std::cout <<"opusc zolwia\n";
		window->addOperation(std::pair<int, int>(5,0));
	}
	else if(operation == "CS")
	{
		std::cout <<"wyczysc ekran \n"; 
		window->addOperation(std::pair<int, int>(9,0));
	}
	else if (operation == "SETPC")
	{
		std::cout <<"ustaw kolo piora[r,g,b] : " << children[0]->calc(executer) <<
				children[1]->calc(executer) << children[2]->calc(executer)<<"\n"; 
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


