#include "ArgumentsDecAstNode.h"
#include "StartAstNode.h"
#include <iostream>

ArgumentsDecAstNode::ArgumentsDecAstNode(AstNode* parent)
:AstNode(parent)
{
}

int ArgumentsDecAstNode::getArgumentsNumber()
{
	if(this->children.size() > 0)
	{
		return 1 + (dynamic_cast<ArgumentsDecAstNode*>(children[0]))->getArgumentsNumber();
	}
	
	return 1;
}


float ArgumentsDecAstNode::calculate()
{
	return 0;
}

void ArgumentsDecAstNode::check()
{
	//szukamy tylko na jednym poziomie!
	StartAstNode* startAstNode = dynamic_cast<StartAstNode*>(FindStart(this));
	if(startAstNode == nullptr) std::cout << "ERROR: I cant find startAstNode. ArgumentsDecAstNode\n";
	
	if(startAstNode->checkVariable(argumentName))
	{
		std::cout << "You cannot use again argument: " << argumentName << " in the same procedure!\n";
		exit(1);
		return;
	}
	else
	{
		startAstNode->addVariable(argumentName, 0); //powinna byc osobny guard!! -do zmiany
	}
	
	if(!children.empty())
	{
		children[0]->check();
	}
}

void ArgumentsDecAstNode::execute()
{
}

void ArgumentsDecAstNode::setArgumentName(std::string argumentName)
{
	this->argumentName = argumentName;
}
