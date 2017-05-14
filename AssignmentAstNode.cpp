#include "AssignmentAstNode.h"
#include <iostream>
#include "InstructionListAstNode.h"
#include "src/Parser/StartAstNode.h"

AssignmentAstNode::AssignmentAstNode(AstNode* parent)
:AstNode(parent)
{
}

void AssignmentAstNode::execute()
{
	std::cout << children[0]->calculate() << std::endl;
	
	//musi wstawic wartosc do najblizszego (lokalnego) instructionList lub innerinnerinstructionlist
	///nie ma znaczenia co zwrocilo, bo oba nody maja taki sam zestaw funkcji
	StartAstNode* startAstNode = dynamic_cast<StartAstNode*>(FindStart(this));

	if(startAstNode->checkVariable(nameOfVariable))
	{
		std::cout << "Error: You cannot override variable: "  << nameOfVariable << "\n";
		//dla calla bedzie przejscie wyzej
	}
	else
	{
		startAstNode->addVariable(nameOfVariable, children[0]->calculate());
	}
}

void AssignmentAstNode::setNameOfVariable(std::string name)
{
	this->nameOfVariable = name;
}

float AssignmentAstNode::calculate()
{
	return 0;
}
