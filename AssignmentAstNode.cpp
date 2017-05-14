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
	if(startAstNode == nullptr) std::cout << "chujnia\n";
	if(startAstNode->checkVariable(nameOfVariable))
	{
		//odwolanie sie poziom wyzej...
		std::cout << "nazwa taka instnieje!\n";
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
