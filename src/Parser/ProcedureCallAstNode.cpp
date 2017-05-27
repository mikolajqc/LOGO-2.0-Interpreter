#include "ProcedureCallAstNode.h"
#include "StartAstNode.h"
#include <iostream>
#include "src/Parser/ArgumentsAstNode.h"

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
	
	
	while(startAstNode != nullptr)
	{
		if(startAstNode->CheckProcedure(procedureName) == true)
		{
			pointerToProcedureDeclaration = static_cast<ProcedureDeclarationAstNode*>(startAstNode->
			GetPointerToProcedureNode(procedureName)); ///CHECK IT!!!
			std::cout << "pointer name: " << pointerToProcedureDeclaration->GetProcedureName() << "\n";
			break;
		}
		else
		{
			startAstNode = dynamic_cast<StartAstNode*>(FindStartForCall(startAstNode));
			std::cout << "chuj\n";
		}
	}
	if(startAstNode == nullptr)
	{
		std::cout << "Error: Procedure: \'" << procedureName << "\' is not declared!\n";
		exit(1);
	}
	
	
	argumentsNumber = children[0]->GetChildren().size();
	
	//arguments
	
	if(argumentsNumber != pointerToProcedureDeclaration->GetArgumentsNumber())
	{
		std::cout << "Error: procedure: " << procedureName << " need " 
		<< pointerToProcedureDeclaration->GetArgumentsNumber() << " you passed " 
		<< argumentsNumber << "!\n";
		exit(1);
		
	}
	std::cout << "test" << children.size()<< "\n";
	if(children.size() > 0) children[0]->check(); //arguments
	
}

void ProcedureCallAstNode::execute(Executer* executer)
{
	std::cout <<"ProcedureCallAstNode executing\n";
	executer->AddContext();
	executer->SetProcedureContext();
	
	for(size_t i = 0; i < children.size(); ++i)
	{
		children[i]->execute(executer);
	}
	
	pointerToProcedureDeclaration->GetChildren()[1]->execute(executer);
	
	std::cout <<"ProcedureCallAstNode executed value: " << executer->GetReturnValue() << "\n";
	executer->DeleteContext();
}

void ProcedureCallAstNode::SetProcedureName(std::string procedureName)
{
	this->procedureName = procedureName;
}

void ProcedureCallAstNode::SetArgumentsNumber(int argumentsNumber)
{
	this->argumentsNumber = argumentsNumber;
}
float ProcedureCallAstNode::calc(Executer* executer)
{
	float result;
	
	std::cout <<"ProcedureCallAstNode calculating\n";
	executer->AddContext();
	executer->SetProcedureContext();
	
	for(size_t i = 0; i < children.size(); ++i)
	{
		children[i]->execute(executer);
	}
	
	pointerToProcedureDeclaration->GetChildren()[1]->execute(executer);
	
	result = executer->GetReturnValue();
	executer->DeleteContext();
	std::cout <<"ProcedureCallAstNode executed\n";
	return result;
}

ProcedureDeclarationAstNode* ProcedureCallAstNode::GetPointerToProcedure()
{
	return pointerToProcedureDeclaration;
}
