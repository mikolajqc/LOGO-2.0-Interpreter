#include "InstructionListAstNode.h"

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
}
