#ifndef CONTEXT_H
#define CONTEXT_H
#include <map>

class Context
{
public:
	Context();
	~Context();
	
	void AddLocalVariable(std::string name, float value);
	void AddArgument(std::string name, float value);
	bool GetVariable(std::string name, float& value);
	
	bool IsProcedureContext();
	void SetProcedureContext();
	
	void SetExecutionBlocked();
	bool IsExecutionBlocked();
	
	void SetReturnValue(float value);
	float GetReturnValue();
	

private:
	std::map<std::string, float> localVariables;
	std::map<std::string, float> arguments;
	
	bool GetLocalVariable(std::string name, float& value);
	bool GetArgument(std::string name, float& value);
	
	bool isProcedureContext;
	bool isExecutionBlocked;
	
	float returnValue;
	
};

#endif // CONTEXT_H
