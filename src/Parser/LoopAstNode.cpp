#include "LoopAstNode.h"
#include <iostream>

LoopAstNode::LoopAstNode(AstNode* parent)
:AstNode(parent)
{
}

float LoopAstNode::calculate()
{
	return 0;
}

void LoopAstNode::execute(Executer* executer)
{
	numberOfLoops = children[0]->calc(executer);
	std::cout << "NumberOfLoops: " << numberOfLoops << "\n";
	
	for(int i = 0; i < numberOfLoops; ++i)
	{
		children[1]->execute(executer);
	}
}

void LoopAstNode::check()
{
	numberOfLoops = children[0]->calculate();
	std::cout << "NumberOfLoops: " << numberOfLoops << "\n";
	children[1]->check();
}
float LoopAstNode::calc(Executer* executer)
{
}

