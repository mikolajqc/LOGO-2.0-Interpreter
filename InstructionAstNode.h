#ifndef INSTRUCTIONASTNODE_H
#define INSTRUCTIONASTNODE_H
#include "AstNode.h"

class InstructionAstNode : public AstNode
{
public:
	InstructionAstNode(AstNode* parent);

	void execute();
	float calculate();
	void check();
};

#endif // INSTRUCTIONASTNODE_H
