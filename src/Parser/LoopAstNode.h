#ifndef LOOPASTNODE_H
#define LOOPASTNODE_H
#include "AstNode.h"

class LoopAstNode :public AstNode
{
public:
	float calculate();
	void execute();
	void check();
	
	LoopAstNode(AstNode* parent);

private:
	int numberOfLoops;
};

#endif // LOOPASTNODE_H
