#ifndef EXPASTNODE_H
#define EXPASTNODE_H

#include "AstNode.h"

class ExpAstNode : public AstNode
{
public:
	ExpAstNode(AstNode* parent);

	float calculate();

};

#endif // EXPASTNODE_H
