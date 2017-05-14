#ifndef STARTASTNODE_H
#define STARTASTNODE_H
#include "AstNode.h"
#include "string"
#include "map"

class StartAstNode : public AstNode
{
public:
	StartAstNode(AstNode* parent);

	void execute();
	float calculate();
	void check();
	
	void addVariable(std::string, float value);
	bool checkVariable(std::string);
	float GetValue(std::string);
	
private:
	std::map<std::string, std::pair <AstNode*, std::vector<float> > > procedures;
	std::map<std::string, float> variables;
};

#endif // STARTASTNODE_H
