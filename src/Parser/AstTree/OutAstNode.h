#ifndef OUTASTNODE_H
#define OUTASTNODE_H
#include "AstNode.h"

class OutAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void execute(Executer* executer);
	void check();
	
	OutAstNode(AstNode* parent, Window*);
	
	void SetOperation(std::string operation);
	std::string GetOperation();


private:
	std::string operation;

};


#endif // TEMPASTNODE_H
