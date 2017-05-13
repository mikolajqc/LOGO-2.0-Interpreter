#ifndef VALASTNODE_H
#define VALASTNODE_H

#include "AstNode.h"
#include <string>

class ValAstNode : public AstNode
{
public:
	ValAstNode(AstNode* parent);
	
	void SetValue(std::string value);

private:
	float numericValue;
	std::string textValue;
};

#endif // VALASTNODE_H
