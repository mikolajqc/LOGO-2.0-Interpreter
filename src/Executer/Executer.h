#ifndef EXECUTER_H
#define EXECUTER_H

#include <vector>
#include "Parser.h"
#include "StackOfContext.h"

class Executer
{
public:
	Executer();
	~Executer();
	
	void execute();
	//void stackTest();
	
	void AddContext();
	void DeleteContext();
	
	void AddLocalVariable(std::string name, float value);
	void AddArgument(std::string name, float value);
	void AddProcedure(std::string procedureName, AstNode* pointerToProcedure,
					std::vector<std::string> argumentsNames);
	
	float GetVariable(std::string name); //zwraca wartosc (nie wazne skad czy args czy local)
	AstNode* GetPointerToProcedure(std::string procedureName);
	
	void ExecuterTest();

private:
	Parser* parser;
	
	StackOfContext stackOfContexts;
	
	std::map<std::string, std::pair <AstNode*, std::vector<std::string> > > procedures;
};

#endif // EXECUTER_H
