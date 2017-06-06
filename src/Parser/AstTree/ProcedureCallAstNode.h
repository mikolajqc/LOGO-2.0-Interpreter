#ifndef PROCEDURECALLASTNODE_H
#define PROCEDURECALLASTNODE_H
#include "AstNode.h"
#include <string>
#include <src/Parser/AstTree/ProcedureDeclarationAstNode.h>

class ProcedureCallAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	
	ProcedureCallAstNode(AstNode* parent, Window*);
	
	void SetProcedureName(std::string procedureName);
	void SetArgumentsNumber(int argumentsNumber);
	
	ProcedureDeclarationAstNode* GetPointerToProcedure();
	
	
private:
	std::string procedureName;
	int argumentsNumber;
	
	ProcedureDeclarationAstNode* pointerToProcedureDeclaration;
};

#endif // PROCEDURECALLASTNODE_H
