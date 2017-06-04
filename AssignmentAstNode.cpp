#include "AssignmentAstNode.h"
#include <iostream>
#include "InstructionListAstNode.h"
#include "src/Parser/StartAstNode.h"

AssignmentAstNode::AssignmentAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
}

void AssignmentAstNode::execute(Executer* executer)
{
	//std::cout << "AssignmentAstNode executing\n";
	
	int value = children[0]->calc(executer);
	
	executer->AddLocalVariable(nameOfVariable, value);
	
	//std::cout << "value: " << value << "\n";
	
	
}

void AssignmentAstNode::setNameOfVariable(std::string name)
{
	this->nameOfVariable = name;
}

float AssignmentAstNode::calculate()
{
	return 0;
}

void AssignmentAstNode::check()
{
	std::cout << children[0]->calculate() << std::endl;
	
	//musi wstawic wartosc do najblizszego (lokalnego) instructionList lub innerinnerinstructionlist
	///nie ma znaczenia co zwrocilo, bo oba nody maja taki sam zestaw funkcji
	StartAstNode* startAstNode = dynamic_cast<StartAstNode*>(FindStart(this));

	if(startAstNode->checkVariable(nameOfVariable))
	{
		std::cout << "Error: You cannot override variable: "  << nameOfVariable << "\n";
		exit(1);
	}
	else
	{
		startAstNode->addVariable(nameOfVariable, children[0]->calculate());
	}
}
float AssignmentAstNode::calc(Executer* executer)
{
}

