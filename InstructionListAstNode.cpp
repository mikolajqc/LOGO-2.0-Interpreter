#include "InstructionListAstNode.h"
#include <iostream>

InstructionListAstNode::InstructionListAstNode(AstNode* parent, Window* window)
:AstNode(parent, window )
{
	
}

void InstructionListAstNode::execute(Executer* executer)
{
	std::cout << "InstructionListAstNode executing\n";
	
	//executer->AddContext();
	
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

