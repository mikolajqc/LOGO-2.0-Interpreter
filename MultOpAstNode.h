#ifndef MULTOPASTNODE_H
#define MULTOPASTNODE_H
#include "AstNode.h"

class MultOpAstNode : public AstNode
{
public:
	MultOpAstNode(AstNode* parent);

	void setIsMult(bool isMult);
	float calculate(); //0 when minus and 1 when plus
	void execute();
	void check();

private:
	bool isMult;
};

#endif // MULTOPASTNODE_H
