#include "AssignmentAstNode.h"
#include <iostream>

AssignmentAstNode::AssignmentAstNode(AstNode* parent)
:AstNode(parent)
{
}

void AssignmentAstNode::execute()
{
	std::cout << children[0]->calculate() << std::endl;
}

void AssignmentAstNode::setNameOfVariable(std::string name)
{
	this->nameOfVariable = name;
}

float AssignmentAstNode::calculate()
{
}
