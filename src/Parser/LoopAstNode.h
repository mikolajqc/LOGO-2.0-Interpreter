#ifndef LOOPASTNODE_H
#define LOOPASTNODE_H
#include "AstNode.h"

class LoopAstNode :public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void execute(Executer* executer);
	void check();
	
	LoopAstNode(AstNode* parent, Window*);

private:
	int numberOfLoops;
};

#endif // LOOPASTNODE_H
