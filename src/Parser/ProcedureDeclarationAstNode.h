#ifndef PROCEDUREDECLARATIONASTNODE_H
#define PROCEDUREDECLARATIONASTNODE_H
#include "AstNode.h"
#include "string"

class ProcedureDeclarationAstNode : public AstNode
{
public:
float calc(Executer* executer);

	float calculate();
	void check();
	void execute(Executer* executer);
	
	void SetProcedureName(std::string);
	void SetArgumentsNumber(int argumentsNumber);
	
	//debug:
	std::string GetProcedureName();
	int GetArgumentsNumber();
	
	ProcedureDeclarationAstNode(AstNode* parent);

private:
	std::string procedureName;
	int argumentsNumber;

};

#endif // PROCEDUREDECLARATIONASTNODE_H
