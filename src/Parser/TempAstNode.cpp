#include "TempAstNode.h"
#include <iostream>

TempAstNode::TempAstNode(AstNode* parent)
:AstNode(parent)
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
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"zolw do gory o: " <<children[0]->calc(executer) << "\n"; 
	}
	else if(operation == "BK")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"zolw w dol o: " <<children[0]->calc(executer) << "\n"; 
	}
	else if(operation == "RT")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"zolw w prawo o: " <<children[0]->calc(executer) << "\n"; 
	}
	else if(operation == "LT")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"zolw w lewo o: " <<children[0]->calc(executer) << "\n"; 
	}
	else if(operation == "PU")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"podnies zolwia! \n"; 
	}
	else if(operation == "PD")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"opusc zolwia\n"; 
	}
	else if(operation == "CS")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"wyczysc ekran \n"; 
	}
	else if (operation == "SETPC")
	{
		std::cout <<"ustaw kolo piora[r,g,b] : " << children[0]->calc(executer) <<
				children[1]->calc(executer) << children[2]->calc(executer)<<"\n"; 
	}
	/*
	else if(operation == "STOP")
	{
		executer->SetReturnValue(0);
	}
	*/
	//std::cout <<"zolw do gory o\n";
	//return 1;
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
	if(operation == "FD")
	{
		//executer->SetReturnValue(children[0]->calc(executer));
		std::cout <<"zolw do gory o: " <<children[0]->calc(executer) << "\n"; 
	}
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


