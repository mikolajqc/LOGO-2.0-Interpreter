#include "StartAstNode.h"
#include "iostream"

StartAstNode::StartAstNode(AstNode* parent, Window* window)
:AstNode(parent, window)
{
	
}

void StartAstNode::execute(Executer* executer)
{
	std::cout << "StartAstNode executing\n";
	for (unsigned int i = 0; i < children.size(); ++i)
	{
		children[i]->execute(executer);
	}
}

float StartAstNode::calculate()
{
	return 0;
}

void StartAstNode::addVariable(std::string variableName, float value)
{
	std::cout << "Adding variable to table: " << variableName << " " << value  << "\n";
	variables.insert(std::pair<std::string, float>(variableName, value));
}

bool StartAstNode::checkVariable(std::string variableName)
{
	if(variables.count(variableName) > 0)
	{
		return true;
	}
	
	return false;
}

float StartAstNode::GetValue(std::string variableName)
{
	if(variables.count(variableName) > 0)
	{
		return variables[variableName];
	}
	else
	{
		std::cout << "ERROR: No such variable Name in StartNode!\n";
	}
	return -1;
}

void StartAstNode::check()
{
	//children[0]->check();
	for(unsigned int i = 0 ; i < children.size(); ++i)
	{
		children[i]->check();
	}
}

bool StartAstNode::CheckProcedure(std::string procedureName)
{
	if(procedures.count(procedureName) > 0)
	{
		return true;
	}
	
	return false;
}

void StartAstNode::AddProcedure(std::string procedureName, AstNode* pointerToProcedureNode)
{
	std::cout << "Adding procedure to table: " << procedureName << "\n";
			
	procedures.insert(std::pair<std::string,AstNode*>(procedureName, pointerToProcedureNode));
}

AstNode* StartAstNode::GetPointerToProcedureNode(std::string procedureName)
{
	if(procedures.count(procedureName) > 0)
	{
		return procedures[procedureName];
	}
	else
	{
		std::cout << "ERROR: No such procedure Name"<<procedureName <<"in StartNode!\n";
	}
	return nullptr;
}

int StartAstNode::GetArgumentsNumber()
{
	std::cout << "children number: " << children.size() << "\n";
	return children.size();
	
}
float StartAstNode::calc(Executer* executer)
{
}

