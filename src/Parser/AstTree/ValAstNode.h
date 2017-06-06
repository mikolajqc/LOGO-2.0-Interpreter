#ifndef VALASTNODE_H
#define VALASTNODE_H

#include "AstNode.h"
#include <string>

//class Executer;

class ValAstNode : public AstNode
{
public:
float calc(Executer* executer);
//narazie tylko liczby 
	ValAstNode(AstNode* parent, Window*);
	
	void SetValue(std::string value);
	void SetIsVariable(bool isVariable);
	
	float calculate(); // ten node jest lisciem wiec nie schodzi nizej.
	void execute(Executer* executer);
	void check();
	
private:
	float numericValue;
	std::string textValue;
	
	bool isVariable;
};

#endif // VALASTNODE_H
