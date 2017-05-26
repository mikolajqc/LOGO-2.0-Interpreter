#include "Context.h"
#include <iostream>

Context::Context()
{
}

Context::~Context()
{
}

void Context::AddLocalVariable(std::string name, float value)
{
	localVariables.insert(std::pair<std::string, float>(name,value));
}

void Context::AddArgument(std::string name, float value)
{
	arguments.insert(std::pair<std::string, float>(name,value));
}

bool Context::GetVariable(std::string name, float& value)
{
	if(GetLocalVariable(name,value) || GetArgument(name, value))
	{
		return true;
	}
	return false;
}

bool Context::GetLocalVariable(std::string name, float& value)
{
	if(localVariables.count(name) != 0)
	{
		value = localVariables[name];
		return true;
	}
	return false; // brak elementu
}

bool Context::GetArgument(std::string name, float& value)
{
	if(arguments.count(name) != 0)
	{
		value = arguments[name];
		return true;
	}
	return false; // brak elementu
}
