#include "TempAstNode.h"

TempAstNode::TempAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

float TempAstNode::calculate()
{
	return -1;
}

void TempAstNode::execute()
{
	//children[0]->execute();
}

void TempAstNode::check()
{
	//children[0]->check();
}
