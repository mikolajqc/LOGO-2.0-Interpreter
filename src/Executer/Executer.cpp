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
}
