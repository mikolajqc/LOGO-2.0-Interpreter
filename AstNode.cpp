#include "AstNode.h"
#include <iostream>
#include "InstructionAstNode.h"
#include "InstructionListAstNode.h"
#include "src/Parser/StartAstNode.h"

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

void AstNode::execute() ///TEMPORARY !!!!! poki co execute jest wykonywane w ramach semantyki - do zmiany
{
	std::cout << "executeAstNode\n";
	children[0]->execute();
}


AstNode* AstNode::FindStart(AstNode* sourceNode)
{
	StartAstNode* startNode;
	///innerInsNode
	AstNode* currentNode = sourceNode->getParent();
	while(!(startNode = dynamic_cast<StartAstNode*>(currentNode)))
	{
		currentNode = currentNode->parent;
		if(currentNode == nullptr) return nullptr;
	}
	
	return startNode;
}
