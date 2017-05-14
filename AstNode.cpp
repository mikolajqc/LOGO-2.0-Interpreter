#include "AstNode.h"
#include <iostream>

AstNode::AstNode(AstNode* parent)
:parent(parent)
{
}

AstNode::~AstNode()
{
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		delete children[i];
	}
}

void AstNode::AddChild(AstNode* astNode)
{
	children.push_back(astNode);
}

AstNode* AstNode::getParent()
{
	return parent;
}

float AstNode::calculate()
{
	return 0; //this will be virtual
}

void AstNode::execute() ///TEMPORARY !!!!!
{
	std::cout << "executeAstNode\n";
	children[0]->execute();
}