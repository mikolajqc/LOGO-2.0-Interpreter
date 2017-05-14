#ifndef TEMPASTNODE_H
#define TEMPASTNODE_H
#include "AstNode.h"

class TempAstNode : public AstNode
{
public:
	float calculate();
	void execute();
	void check();
	
	TempAstNode(AstNode* parent);


};


#endif // TEMPASTNODE_H
