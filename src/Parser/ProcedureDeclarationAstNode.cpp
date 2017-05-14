#include "ProcedureDeclarationAstNode.h"
#include "StartAstNode.h"
#include <iostream>
#include "ArgumentsDecAstNode.h"

ProcedureDeclarationAstNode::ProcedureDeclarationAstNode(AstNode* parent)
:AstNode(parent)
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
	children[0]->check();
	
	//checking inner
	children[1]->check(); //inner instructions list with guard
	
	///calculating arguments number
	//std::cout << "hrllo";
	argumentsNumber = (dynamic_cast<ArgumentsDecAstNode*>(children[0]->GetChildren()[0]))->getArgumentsNumber();
	std::cout << "NumberOfArguments: " << argumentsNumber << "\n";
}

void ProcedureDeclarationAstNode::execute()
{
}

void ProcedureDeclarationAstNode::SetProcedureName(std::string procedureName)
{
	this->procedureName = procedureName;
}
