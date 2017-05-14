#ifndef PROCEDUREDECLARATIONASTNODE_H
#define PROCEDUREDECLARATIONASTNODE_H
#include "AstNode.h"
#include "string"

class ProcedureDeclarationAstNode : public AstNode
{
public:

	float calculate();
	void check();
	void execute();
	
	void SetProcedureName(std::string);
	
	ProcedureDeclarationAstNode(AstNode* parent);

private:
	std::string procedureName;
	int argumentsNumber;

};

#endif // PROCEDUREDECLARATIONASTNODE_H
