#include "ArgumentsAstNode.h"
#include <iostream>
#include <vector>
#include "ProcedureCallAstNode.h"

ArgumentsAstNode::ArgumentsAstNode(AstNode* parent)
:AstNode(parent)
{
}


float ArgumentsAstNode::calculate()
{
	return 0;
}

void ArgumentsAstNode::check()
{
	std::cout << "checking Arguments\n";
	
	for(size_t i = 0; i < children.size(); ++i)
	{
		children[i]->calculate();
	}
	
}

void ArgumentsAstNode::execute(Executer* executer)
{
	std::cout << "ArgumentsAstNode executing\n";
	std::vector<std::string> argumentsNames = (dynamic_cast<ProcedureCallAstNode*>(parent))->GetPointerToProcedure()->GetArgumentsNames();
	
	for(size_t i = 0; i < children.size(); ++i)
	{
		executer->AddArgument(argumentsNames[i],children[i]->calc(executer));
	}
	
	//children[0]->calc(executer);
	//if(children.size() > 1)children[1]->execute(executer);
}

int ArgumentsAstNode::GetArgumentsNumber()
{
	//if(this->children.size() > 1)
	//{
		//return 1 + (dynamic_cast<ArgumentsAstNode*>(children[1]))->GetArgumentsNumber();
	//}
	
	return 2;
}
float ArgumentsAstNode::calc(Executer* executer)
{
	return 0;
}

