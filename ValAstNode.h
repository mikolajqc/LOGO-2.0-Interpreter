#ifndef VALASTNODE_H
#define VALASTNODE_H

#include "AstNode.h"
#include <string>

class ValAstNode : public AstNode
{
public:
//narazie tylko liczby 
	ValAstNode(AstNode* parent);
	
	void SetValue(std::string value);
	void SetIsVariable(bool isVariable);
	
	float calculate(); // ten node jest lisciem wiec nie schodzi nizej.

private:
	float numericValue;
	std::string textValue;
	
	bool isVariable;
};

#endif // VALASTNODE_H
