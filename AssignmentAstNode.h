#ifndef ASSIGNMENTASTNODE_H
#define ASSIGNMENTASTNODE_H
#include "AstNode.h"
#include "string"

class AssignmentAstNode : public AstNode
{
public:
	AssignmentAstNode(AstNode* parent);

	void execute();
	float calculate();
	void setNameOfVariable(std::string name);
	void check();
	
private:
	std::string nameOfVariable;
};

#endif // ASSIGNMENTASTNODE_H
