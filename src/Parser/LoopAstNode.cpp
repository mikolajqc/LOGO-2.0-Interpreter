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

void LoopAstNode::execute()
{
	//std::cout << children[0]->calculate() << "\n"; //exp - tyle razy sie wykona kod w drugim dziecku
	numberOfLoops = children[0]->calculate();
	std::cout << "NumberOfLoops: " << numberOfLoops << "\n";
	children[1]->execute();
}

void LoopAstNode::check()
{
	numberOfLoops = children[0]->calculate();
	std::cout << "NumberOfLoops: " << numberOfLoops << "\n";
	children[1]->check();
}
