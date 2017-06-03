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
	
	//void addVariable(std::string, float value);
	//bool checkVariable(std::string);
	
private:
	//table of symbols
	//std::map<std::string, std::pair <AstNode*, std::vector<float> > > procedures;
	//std::map<std::string, float> variables;
	
};

#endif // INSTRUCTIONLISTASTNODE_H
