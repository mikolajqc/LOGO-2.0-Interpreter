#ifndef EXECUTER_H
#define EXECUTER_H
#include <vector>

#include "StackOfContext.h"


class Executer
{
public:
	Executer();
	~Executer();
	
	void execute();
	
	void AddContext();
	void DeleteContext();
	
	void AddLocalVariable(std::string name, float value);
	void AddArgument(std::string name, float value);
	void AddProcedure(std::string procedureName, std::vector<std::string> argumentsNames);
	
	float GetVariable(std::string name); //zwraca wartosc (nie wazne skad czy args czy local)
	
	bool IsExecutionBlocked();
	void SetProcedureContext();
	void SetReturnValue(float value);
	float GetReturnValue();
	
	void ExecuterTest();

private:
	StackOfContext stackOfContexts;
	std::map<std::string, std::vector<std::string>  > procedures;
};

#endif // EXECUTER_H
