#include "InstructionAstNode.h"
#include <iostream>

InstructionAstNode::InstructionAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void InstructionAstNode::execute()
{
	std::cout << "InstructionAstNode executing\n";
	for(unsigned int i = 0; i < children.size() ; ++i)
	{
		children[i]->execute();
	}
}

float InstructionAstNode::calculate()
{
	return 0;
}

void InstructionAstNode::check()
{
	children[0]->check();
}
