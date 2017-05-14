#include "StartAstNode.h"
#include "iostream"

StartAstNode::StartAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void StartAstNode::execute()
{
	children[0]->execute();
}

float StartAstNode::calculate()
{
	return 0;
}

void StartAstNode::addVariable(std::string variableName, float value)
{
	std::cout << "Adding variable to table: " << variableName << " " << value  << "\n";
	variables.insert(std::pair<std::string, float>(variableName, value));
}

bool StartAstNode::checkVariable(std::string variableName)
{
	if(variables.count(variableName) > 0)
	{
		return true;
	}
	
	return false;
}

float StartAstNode::GetValue(std::string variableName)
{
	if(variables.count(variableName) > 0)
	{
		return variables[variableName];
	}
	else
	{
		std::cout << "ERROR: No such variable Name in StartNode!\n";
	}
	return -1;
}
