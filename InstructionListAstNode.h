#ifndef INSTRUCTIONLISTASTNODE_H
#define INSTRUCTIONLISTASTNODE_H
#include "AstNode.h"
#include <map>

class InstructionListAstNode : public AstNode
{
public:
	float calc(Executer* executer);
	InstructionListAstNode(AstNode* parent, Window*);
	
	void execute(Executer* executer);
	float calculate();
	void check();
	
};

#endif // INSTRUCTIONLISTASTNODE_H
