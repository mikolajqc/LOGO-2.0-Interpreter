#ifndef INSTRUCTIONASTNODE_H
#define INSTRUCTIONASTNODE_H
#include "AstNode.h"

class InstructionAstNode : public AstNode
{
public:
float calc(Executer* executer);
	InstructionAstNode(AstNode* parent, Window*);

	void execute(Executer* executer);
	float calculate();
	void check();
};

#endif // INSTRUCTIONASTNODE_H
