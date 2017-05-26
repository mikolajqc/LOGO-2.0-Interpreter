#ifndef QCONDITIONASTNODE_H
#define QCONDITIONASTNODE_H
#include "AstNode.h"
#include <string>

class QConditionAstNode : public AstNode
{
public:
float calc(Executer* executer);
	float calculate();
	void check();
	void execute(Executer* executer);
	
	void SetOperatorInString(std::string operatorInString);
	
	QConditionAstNode(AstNode* parent);
	
private:
	std::string operatorInString;
};

#endif // QCONDITIONASTNODE_H
