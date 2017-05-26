#include "InstructionListAstNode.h"
#include <iostream>

InstructionListAstNode::InstructionListAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void InstructionListAstNode::execute()
{
	std::cout << "InstructionListAstNode executing\n";
	for(unsigned int i = 0; i < children.size() ; ++i)
	{
		children[i]->execute();
	}
}

float InstructionListAstNode::calculate()
{
	return 0;
}

void InstructionListAstNode::check()
{
	
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		children[i]->check();
	}
	
}