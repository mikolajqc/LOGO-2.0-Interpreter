#include "InstructionAstNode.h"
#include <iostream>

InstructionAstNode::InstructionAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void InstructionAstNode::execute(Executer* executer)
{
	std::cout << "InstructionAstNode executing\n";
	
	//executer->AddContext();
	
	for(unsigned int i = 0; i < children.size() ; ++i)
	{
		children[i]->execute(executer);
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
float InstructionAstNode::calc(Executer* executer)
{
}

