#ifndef SEXPASTNODE_H
#define SEXPASTNODE_H
#include "AstNode.h"

class SExpAstNode : public AstNode
{
public:
	SExpAstNode(AstNode* parent);

	float calculate();
	void execute();
	void check();
	
};

#endif // SEXPASTNODE_H
