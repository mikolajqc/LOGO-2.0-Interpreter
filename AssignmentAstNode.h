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
	
	
private:
	std::string nameOfVariable;
};

#endif // ASSIGNMENTASTNODE_H
