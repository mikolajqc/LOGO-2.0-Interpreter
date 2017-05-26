#ifndef STARTASTNODE_H
#define STARTASTNODE_H
#include "AstNode.h"
#include "string"
#include "map"

class StartAstNode : public AstNode
{
public:
	float calc(Executer* executer);
	
	StartAstNode(AstNode* parent);

	void execute(Executer* executer);
	float calculate();
	void check();
	
	void addVariable(std::string, float value);
	bool checkVariable(std::string);
	float GetValue(std::string);
	int GetArgumentsNumber(); //only for start in proceduredeclaration
	
	bool CheckProcedure(std::string procedureName);
	void AddProcedure(std::string procedureName, AstNode* pointerToProcedureNode);
	AstNode* GetPointerToProcedureNode(std::string procedureName);
	
	
private:
	std::map<std::string, AstNode* > procedures;
	std::map<std::string, float> variables;
};

#endif // STARTASTNODE_H
