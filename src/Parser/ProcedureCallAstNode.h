#ifndef PROCEDURECALLASTNODE_H
#define PROCEDURECALLASTNODE_H
#include "AstNode.h"
#include <string>
#include <src/Parser/ProcedureDeclarationAstNode.h>

class ProcedureCallAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	
	ProcedureCallAstNode(AstNode* parent);
	
	void SetProcedureName(std::string procedureName);
	void SetArgumentsNumber(int argumentsNumber);
	
private:
	std::string procedureName;
	int argumentsNumber;
	
	ProcedureDeclarationAstNode* pointerToProcedureDeclaration;
};

#endif // PROCEDURECALLASTNODE_H
