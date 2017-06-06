#ifndef SEXPASTNODE_H
#define SEXPASTNODE_H
#include "AstNode.h"

class SExpAstNode : public AstNode
{
public:

	float calc(Executer* executer);
	SExpAstNode(AstNode* parent, Window*);

	float calculate();
	void execute(Executer* executer);
	void check();
	
};

#endif // SEXPASTNODE_H
