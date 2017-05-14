#ifndef LOOPASTNODE_H
#define LOOPASTNODE_H
#include "AstNode.h"

class LoopAstNode :public AstNode
{
public:
	float calculate();
	void execute();
	LoopAstNode(AstNode* parent);

private:
	int numberOfLoops;
};

#endif // LOOPASTNODE_H
