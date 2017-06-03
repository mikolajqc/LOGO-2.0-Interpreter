#include "AstNode.h"
#include <iostream>
#include "InstructionAstNode.h"
#include "InstructionListAstNode.h"
#include "src/Parser/StartAstNode.h"
#include "src/Parser/ProcedureDeclarationAstNode.h"

AstNode::AstNode(AstNode* parent, Window* window)
:parent(parent), window(window)
{
}

AstNode::~AstNode()
{
	for(unsigned int i = 0; i < children.size(); ++i)
	{
		if(children[i] != nullptr) delete children[i];
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
	return 0;
}

void AstNode::execute(Executer* executer) ///TEMPORARY !!!!! poki co execute jest wykonywane w ramach semantyki - do zmiany
{
	std::cout << "executeAstNode\n";
	children[0]->execute(executer);
}

AstNode* AstNode::FindStartForCall(AstNode* sourceNode)
{
	
	StartAstNode* startNode;
	///innerInsNode
	AstNode* currentNode = sourceNode->getParent();
	if(currentNode == nullptr) return nullptr;
	while(!(startNode = dynamic_cast<StartAstNode*>(currentNode)))
	{
		std::cout << "I am in \n";
		
		currentNode = currentNode->parent;
		std::cout << "I am in2 \n";
		if(currentNode == nullptr) 
		{
			exit(1);
		}
	}
	
	return startNode;
	
}


AstNode* AstNode::FindStart(AstNode* sourceNode)
{
	StartAstNode* startNode;
	///innerInsNode
	AstNode* currentNode = sourceNode->getParent();
	if(currentNode == nullptr) return nullptr;
	while(!(startNode = dynamic_cast<StartAstNode*>(currentNode)))
	{
		std::cout << "I am in \n";
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