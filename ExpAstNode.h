#ifndef EXPASTNODE_H
#define EXPASTNODE_H

#include "AstNode.h"

class ExpAstNode : public AstNode
{
public:
float calc(Executer* executer);
	ExpAstNode(AstNode* parent);

	float calculate();
	void  execute(Executer* executer);
	void check();

};

#endif // EXPASTNODE_H
