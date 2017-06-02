#include "Executer.h"
#include <iostream>

Executer::Executer()
{
	//parser = new Parser;
}

Executer::~Executer()
{
	//delete parser;
}

void Executer::execute()
{
	ExecuterTest();
}

void Executer::AddContext()
{
	
	stackOfContexts.push(new Context);
	std::cout << "Context added!\n";
}

void Executer::DeleteContext()
{
	
	stackOfContexts.pop();
	std::cout << "Context deleted!\n";
}

void Executer::AddLocalVariable(std::string name, float value)
{ 
	
	stackOfContexts.GetTopPosition()->AddLocalVariable(name, value);
	std::cout << "LocalVariable added!\n";
}

void Executer::AddArgument(std::string name, float value)
{
	
	stackOfContexts.GetTopPosition()->AddArgument(name, value);
	std::cout << "argument added! "<< value << "\n";
}

void Executer::AddProcedure(std::string procedureName, std::vector<std::string> argumentsNames)
{
	
	procedures[procedureName] = argumentsNames;
	std::cout << "procedure added!\n";
}

float Executer::GetVariable(std::string name)
{
	float result;
	
	for(int i = stackOfContexts.size() - 1; i >= 0 ; --i)
	{
		if(stackOfContexts.GetPosition(i)->GetVariable(name, result))
		{
			return result; //jesli znalazlo zmienna zwroc ja
		}
	}
	
	std::cout << "ERROR!: Cannot to find variable on stack!\n";
	exit(1);
	
}


void Executer::ExecuterTest()
{
	AddContext();
	AddArgument("c", 10);
	AddLocalVariable("a", 100);
	
	std::vector<std::string> testVector;
	
	AddContext();
	AddArgument("b", 123);
	AddLocalVariable("a", 12);
	
	std::cout << "a: " <<  GetVariable("a") << "\n";
	std::cout << "b: " <<  GetVariable("b") << "\n";
	std::cout << "c: " <<  GetVariable("c") << "\n";
	
}

/*
void Executer::SetExecutionBlocked()
{
	for(int i = stackOfContexts.size() - 1; i >= 0 ; --i)
	{
		stackOfContexts.GetPosition(i)->SetExecutionBlocked();
		
		if(stackOfContexts.GetPosition(i)->IsProcedureContext())
		{
			//doszlismy do kontekstu procedury
			return;
		}
	}
}
*/

bool Executer::IsExecutionBlocked()
{
	return stackOfContexts.GetTopPosition()->IsExecutionBlocked();
}

void Executer::SetProcedureContext()
{
	stackOfContexts.GetTopPosition()->SetProcedureContext();
}

void Executer::SetReturnValue(float value)
{
	for(int i = stackOfContexts.size() - 1; i >= 0 ; --i)
	{
		stackOfContexts.GetPosition(i)->SetExecutionBlocked();
		if(stackOfContexts.GetPosition(i)->IsProcedureContext())
		{
			stackOfContexts.GetPosition(i)->SetReturnValue(value);
			return;
		}
	}
}

float Executer::GetReturnValue()
{
	if(!stackOfContexts.GetTopPosition()->IsProcedureContext())
	{
		std::cout << "Error!: You cannot get return value here!\n";
		exit(1);
	}
	return stackOfContexts.GetTopPosition()->GetReturnValue();
}
