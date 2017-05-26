#include "Executer.h"

Executer::Executer()
{
	parser = new Parser;
}

Executer::~Executer()
{
	delete parser;
}

void Executer::execute()
{
	parser->start(); // parsing
	parser->check(); //semantic analysis
	parser->execute();
	ExecuterTest();
}

void Executer::AddContext()
{
	stackOfContexts.push(new Context);
}

void Executer::DeleteContext()
{
	stackOfContexts.pop();
}

void Executer::AddLocalVariable(std::string name, float value)
{
	stackOfContexts.GetTopPosition()->AddLocalVariable(name, value);
}

void Executer::AddArgument(std::string name, float value)
{
	stackOfContexts.GetTopPosition()->AddArgument(name, value);
}

void Executer::AddProcedure(std::string procedureName, AstNode* pointerToProcedure,  std::vector<std::string> argumentsNames)
{
	std::pair <AstNode*, std::vector<std::string> > procedure =
			std::pair<AstNode*, std::vector<std::string> >(pointerToProcedure, argumentsNames);
	std::cout << "1 , 2, 3 (potem jest 4) ";
	procedures[procedureName] = procedure; /// check it!!!!!!!!!!!!!
	std::cout << "4\n";
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
	
	std::cout << "ERROR!: Po przejsciu przez stack nie znalezlismy zmiennej!\n";
	exit(1);
	
}

AstNode* Executer::GetPointerToProcedure(std::string procedureName)
{
	return procedures[procedureName].first;
}

void Executer::ExecuterTest()
{
	AddContext();
	AddArgument("a", 10);
	AddLocalVariable("a", 100);
	
	std::cout << "a: " <<  GetVariable("a") << "\n";
	
}
