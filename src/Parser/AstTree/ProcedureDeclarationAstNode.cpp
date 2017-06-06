#include "ProcedureDeclarationAstNode.h"
#include "StartAstNode.h"
#include <iostream>
#include "ArgumentsDecAstNode.h"

ProcedureDeclarationAstNode::ProcedureDeclarationAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
}
float ProcedureDeclarationAstNode::calculate()
{
	return -1;
}

void ProcedureDeclarationAstNode::check()
{
	//to nie jest wykonywanie. To jest proces sprawdzania semantyki
	// po 1 sprawdzmy czy cos takiego istnieje w starcie
	StartAstNode* startAstNode = dynamic_cast<StartAstNode*>(FindStart(this));
	if(startAstNode == nullptr) std::cout << "ERROR!: I cant find start node in procedure declaration\n";
	
	if(startAstNode->CheckProcedure(procedureName) == true)
	{
		std::cout << "Error: " << procedureName << " is defined!\n";
		exit(1);
		return;
	}
	else
	{
		startAstNode->AddProcedure(procedureName,this);
	}
	
	//checking argumentsdec
	//std::cout << "Children in declaration: " << children[0]->GetChildren().size() << "\n";
	
	
	
	argumentsNumber = children[0]->GetChildren().size();
	//std::cout << "NumberOfArguments: " << argumentsNumber << "\n";
	if(argumentsNumber > 0)children[0]->check();
	//checking inner
	children[1]->check(); //inner instructions list with guard
	

}

void ProcedureDeclarationAstNode::execute(Executer* executer)
{
	//std::cout << "ProcedureDeclaration execution\n";
	
	//TODO
	executer->AddProcedure(procedureName, GetArgumentsNames());
	//GetArgumentsNames();
}

void ProcedureDeclarationAstNode::SetProcedureName(std::string procedureName)
{
	this->procedureName = procedureName;
}

void ProcedureDeclarationAstNode::SetArgumentsNumber(int argumentsNumber)
{
	this->argumentsNumber = argumentsNumber;
}

std::string ProcedureDeclarationAstNode::GetProcedureName()
{
	return procedureName;
}

int ProcedureDeclarationAstNode::GetArgumentsNumber()
{
	return argumentsNumber;
}
float ProcedureDeclarationAstNode::calc(Executer* executer)
{
	return 0;
}

std::vector<std::string> ProcedureDeclarationAstNode::GetArgumentsNames()
{
	std::vector <std::string> resultVector;
	
	for (size_t i = 0; i < children[0]->GetChildren().size();++i)
	{
		resultVector.push_back((dynamic_cast<ArgumentsDecAstNode*>(children[0]->GetChildren()[i]))->GetArgumentName());
		//std::cout << "args: " << (dynamic_cast<ArgumentsDecAstNode*>(children[0]->GetChildren()[i]))->GetArgumentName() << " ";
	}
	//std::cout <<"\n";
	return resultVector;
}
