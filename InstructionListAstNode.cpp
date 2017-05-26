#include "InstructionListAstNode.h"
#include <iostream>

InstructionListAstNode::InstructionListAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void InstructionListAstNode::execute(Executer* executer)
{
	std::cout << "InstructionListAstNode executing\n";
	
	//executer
	
	for(unsigned int i = 0; i < children.size() ; ++i)
	{
		children[i]->execute(executer);
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
float InstructionListAstNode::calc(Executer* executer)
{
}

