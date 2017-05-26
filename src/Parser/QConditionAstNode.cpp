#include "QConditionAstNode.h"
#include <iostream>

QConditionAstNode::QConditionAstNode(AstNode* parent)
:AstNode(parent)
{
}

float QConditionAstNode::calculate()
{
	if(children.size() == 1)
	{
		return children[0]->calculate();
	}
	else if(children.size() == 2)
	{
		if(operatorInString == "==")
		{
			return  (children[0]->calculate() ==  children[1]->calculate());
		}
		else if(operatorInString == "!=")
		{
			return  (children[0]->calculate() !=  children[1]->calculate());
		}
		else if(operatorInString == ">")
		{
			return  (children[0]->calculate() > children[1]->calculate());
		}
		else if(operatorInString == "<")
		{
			return  (children[0]->calculate() < children[1]->calculate());
		}
		else if(operatorInString == ">=")
		{
			return  (children[0]->calculate() >=  children[1]->calculate());
		}
		else if(operatorInString == "<=")
		{
			return  (children[0]->calculate() <=  children[1]->calculate());
		}
	}
	std::cout << "ERROR: I cant recognize operators!\n";
	return -1;
}

void QConditionAstNode::check()
{
	
}

void QConditionAstNode::execute(Executer* executer)
{
	
}

void QConditionAstNode::SetOperatorInString(std::string operatorInString)
{
	this->operatorInString = operatorInString;
}
float QConditionAstNode::calc(Executer* executer)
{
	if(children.size() == 1)
	{
		return children[0]->calc(executer);
	}
	else if(children.size() == 2)
	{
		if(operatorInString == "==")
		{
			return  (children[0]->calc(executer) ==  children[1]->calc(executer));
		}
		else if(operatorInString == "!=")
		{
			return  (children[0]->calc(executer) !=  children[1]->calc(executer));
		}
		else if(operatorInString == ">")
		{
			return  (children[0]->calc(executer) > children[1]->calc(executer));
		}
		else if(operatorInString == "<")
		{
			return  (children[0]->calc(executer) < children[1]->calc(executer));
		}
		else if(operatorInString == ">=")
		{
			return  (children[0]->calc(executer) >=  children[1]->calc(executer));
		}
		else if(operatorInString == "<=")
		{
			return  (children[0]->calc(executer) <=  children[1]->calc(executer));
		}
	}
	std::cout << "ERROR: I cant recognize operators!\n";
	return -1;
}

