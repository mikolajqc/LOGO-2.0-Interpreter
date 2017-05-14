#include "ValAstNode.h"
#include <iostream>
#include <string>
#include <sstream>


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

ValAstNode::ValAstNode(AstNode* parent)
:AstNode(parent)
{
	
}

void ValAstNode::SetValue(std::string value)
{
	if(value[0] > '0' && value[0] < '9')
	{
		numericValue = StringToNumber(value,  0.0);
	}
	else
	{
		//text
		textValue = value;
	}
}

void ValAstNode::SetIsVariable(bool isVarable)
{
	this->isVariable = isVariable;
}

float ValAstNode::calculate()
{
	float result;
	if(isVariable)
	{
		//TODO: odwolanie do tablicy symboli jakos tam
	}
	else
	{
		result = numericValue;
	}
	
	return result;
}
