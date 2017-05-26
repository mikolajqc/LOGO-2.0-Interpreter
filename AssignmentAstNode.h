#ifndef ASSIGNMENTASTNODE_H
#define ASSIGNMENTASTNODE_H
#include "AstNode.h"
#include "string"

class AssignmentAstNode : public AstNode
{
public:
float calc(Executer* executer);
	AssignmentAstNode(AstNode* parent);

	void execute(Executer* executer);
	float calculate();
	void setNameOfVariable(std::string name);
	void check();
	
private:
	std::string nameOfVariable;
};

#endif // ASSIGNMENTASTNODE_H
