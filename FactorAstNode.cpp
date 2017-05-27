#include "FactorAstNode.h"
#include "src/Parser/ProcedureCallAstNode.h"

FactorAstNode::FactorAstNode(AstNode* parent)
:AstNode(parent)
{
}

float FactorAstNode::calculate()
{
	if(ProcedureCallAstNode* p = (dynamic_cast<ProcedureCallAstNode*>(children[0])))
	{
		children[0]->check();
		return 1;
	}
	return children[0]->calculate();
}

void FactorAstNode::execute(Executer* executer)
{
	
}

void FactorAstNode::check()
{
	
}
float FactorAstNode::calc(Executer* executer)
{
	return children[0]->calc(executer);
}

