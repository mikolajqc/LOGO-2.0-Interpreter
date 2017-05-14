#include "ProcedureCallAstNode.h"
#include "StartAstNode.h"
#include <iostream>

ProcedureCallAstNode::ProcedureCallAstNode(AstNode* parent)
:AstNode(parent)
{
}
float ProcedureCallAstNode::calculate()
{
	return 0;
}

void ProcedureCallAstNode::check()
{
	//is such procedure declared:
	StartAstNode* startAstNode = dynamic_cast<StartAstNode*>(FindStart(this));
	if(startAstNode == nullptr) std::cout << "ERROR!: I cant find start node in procedure declaration\n";
	
	if(startAstNode->CheckProcedure(procedureName) == true)
	{
		pointerToProcedureDeclaration = static_cast<ProcedureDeclarationAstNode*>(startAstNode->
		GetPointerToProcedureNode(procedureName)); ///CHECK IT!!!
		std::cout << "pointer name: " << pointerToProcedureDeclaration->GetProcedureName() << "\n";
	}
	else
	{
		std::cout << "Error: Procedure: \'" << procedureName << "\' is not declared!\n";
		exit(1);
	}
	
	//argumentsNumber = (dynamic_cast<ArgumentsDecAstNode*>(children[0]->GetChildren()[0]))->getArgumentsNumber();
	//std::cout << "NumberOfArguments: " << argumentsNumber << "\n";
	
	children[0]->check(); //arguments
}

void ProcedureCallAstNode::execute()
{
}

void ProcedureCallAstNode::SetProcedureName(std::string procedureName)
{
	this->procedureName = procedureName;
}

void ProcedureCallAstNode::SetArgumentsNumber(int argumentsNumber)
{
	this->argumentsNumber = argumentsNumber;
}
