#include "InstructionAstNode.h"

InstructionAstNode::InstructionAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void InstructionAstNode::execute()
{
	children[0]->execute();
}

float InstructionAstNode::calculate()
{
	return 0;
}

void InstructionAstNode::check()
{
	children[0]->check();
}
