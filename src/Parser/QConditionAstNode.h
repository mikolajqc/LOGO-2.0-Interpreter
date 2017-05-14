#ifndef QCONDITIONASTNODE_H
#define QCONDITIONASTNODE_H
#include "AstNode.h"
#include <string>

class QConditionAstNode : public AstNode
{
public:
	float calculate();
	void check();
	void execute();
	
	void SetOperatorInString(std::string operatorInString);
	
	QConditionAstNode(AstNode* parent);
	
private:
	std::string operatorInString;
};

#endif // QCONDITIONASTNODE_H
