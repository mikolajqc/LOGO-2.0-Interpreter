#include "TempAstNode.h"

TempAstNode::TempAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

float TempAstNode::calculate()
{
	
}

void TempAstNode::execute()
{
	children[0]->execute();
}

