#include "StartAstNode.h"


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
