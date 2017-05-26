#ifndef ADDOPASTNODE_H
#define ADDOPASTNODE_H

#include "AstNode.h"

class AddOpAstNode : public AstNode
{
public:
float calc(Executer* executer);
	AddOpAstNode(AstNode* parent);

	void setIsPlus(bool isPlus);
	float calculate(); //0 when minus and 1 when plus
	void execute(Executer* executer);
	void check();
	

private:
	bool isPlus;
};

#endif // ADDOPASTNODE_H
