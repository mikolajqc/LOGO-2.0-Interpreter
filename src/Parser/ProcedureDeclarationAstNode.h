#ifndef PROCEDUREDECLARATIONASTNODE_H
#define PROCEDUREDECLARATIONASTNODE_H
#include "AstNode.h"

class ProcedureDeclarationAstNode : public AstNode
{
public:

	float calculate();
	void check();
	void execute();
	
	ProcedureDeclarationAstNode(AstNode* parent);


};

#endif // PROCEDUREDECLARATIONASTNODE_H
