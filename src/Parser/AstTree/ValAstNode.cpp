#include "ValAstNode.h"
#include <iostream>
#include <string>
#include <sstream>
#include "src/Parser/StartAstNode.h"

class GetValue;
template <typename T>
T StringToNumber ( std::string &Text, T defValue = T() )
{
    std::stringstream ss;
    for ( std::string::const_iterator i=Text.begin(); i!=Text.end(); ++i )
        if ( isdigit(*i) || *i=='e' || *i=='-' || *i=='+' || *i=='.' )
            ss << *i;
    T result;
    return ss >> result ? result : defValue;
}

ValAstNode::ValAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
	
}

void ValAstNode::SetValue(std::string value)
{
	if(value[0] >= '0' && value[0] <= '9')
	{
		numericValue = StringToNumber(value,  0.0);
	}
	else
	{
		//text
		textValue = value;
	}
}

void ValAstNode::SetIsVariable(bool isVariable)
{
	this->isVariable = isVariable;
}

float ValAstNode::calculate()
{
	float result;
	if(isVariable == true)
	{
		
		StartAstNode* startAstNode = dynamic_cast<StartAstNode*>(FindStart(this));

		while(startAstNode != nullptr)
		{
			if(startAstNode->checkVariable(textValue))
			{
				return startAstNode->GetValue(textValue);
			}
			startAstNode = dynamic_cast<StartAstNode*>(FindStart(startAstNode));
		}
		
	}
	else
	{
		result = numericValue;
	}
	return result;
}

void ValAstNode::execute(Executer* executer)
{
	
}

void ValAstNode::check()
{
}

float ValAstNode::calc(Executer* executer)
{
	
	float result;
	if(isVariable == true)
	{
		//std::cout << "textValue: " << textValue << "\n";
		result = executer->GetVariable(textValue);
	}
	else
	{
		result = numericValue;
	}
	return result;
	
}

