#include "InstructionListAstNode.h"
#include <iostream>

InstructionListAstNode::InstructionListAstNode(AstNode* parent)
:AstNode(parent)
{
}

void InstructionListAstNode::execute()
{
	if(children.size() == 2)
	{
		children[0]->execute();
		children[1]->execute();
	}
	else if(children.size() == 1)
	{
		children[0]->execute();
	}
}

float InstructionListAstNode::calculate()
{
	return 0;
}

void InstructionListAstNode::check()
{
	if(children.size() == 2)
	{
		children[0]->check();
		children[1]->check();
	}
	else if(children.size() == 1)
	{
		children[0]->check();
	}
}
/*
void InstructionListAstNode::addVariable(std::string variableName, float value)
{
	variables.insert(std::pair<std::string, float>(variableName, value));
}

bool InstructionListAstNode::checkVariable(std::string variableName)
{
	if(variables.count(variableName) > 0)
	{
		return true;
	}
	
	return false;
}
*/
