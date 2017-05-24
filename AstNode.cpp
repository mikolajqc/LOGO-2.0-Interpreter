#include "AstNode.h"
#include <iostream>
#include "InstructionAstNode.h"
#include "InstructionListAstNode.h"
#include "src/Parser/StartAstNode.h"
#include "src/Parser/ProcedureDeclarationAstNode.h"

AstNode::AstNode(AstNode* parent)
:parent(parent)
{
}

AstNode::~AstNode()
{
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		//std::cout << "delete child" << i << "\n";
		if(children[i] != nullptr) delete children[i];
		//std::cout << "delete child" << i << "\n";
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
		//AstNode* before = currentNode;
		
		
		ProcedureDeclarationAstNode* n;
		if(n = dynamic_cast<ProcedureDeclarationAstNode*>(currentNode))
		{
			if(sourceNode != n->GetChildren()[0])
			{
				//std::cout << "I am in \n";
				currentNode = currentNode->GetChildren()[0];
				return currentNode;
			}
			else currentNode = currentNode->parent;
		}
		else currentNode = currentNode->parent;
		
		if(currentNode == nullptr) 
		{
			exit(1);
		}
	}
	
	return startNode;
}

std::vector<AstNode*> AstNode::GetChildren()
{
	return children;
}
