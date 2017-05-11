#include "Parser.h"

Parser::Parser()
{
	lexer = new Lexer("test.txt");
}

Parser::~Parser()
{
	delete lexer;
}

void Parser::setCurrentLexeme()
{
	currentLexeme = lexer->NextLexeme();
}


bool Parser::start()
{
	std::cout << "start" << std::endl;
	return instructionList();
}

bool Parser::instructionList()
{
	std::cout << "instructionList" << std::endl;
	return (
		assignment() ||
		procedureCall() ||
		conditional() ||
		loop() ||
		graphics()
	);
		
}

bool Parser::instruction()
{
}

bool Parser::assignment()
{
	std::cout << "assignment" << std::endl;
	return true;
}

bool Parser::exp()
{
}

bool Parser::sExp()
{
}

bool Parser::factor()
{
}

bool Parser::multOp()
{
}

bool Parser::addOp()
{
}

bool Parser::arguments()
{
}

bool Parser::procedureCall()
{
	std::cout << "procedureCall" << std::endl;
	return true;
}

bool Parser::out()
{
}

bool Parser::graphics()
{
	std::cout << "graphics" << std::endl;
	return true;
}

bool Parser::innerInstructionsList()
{
}

bool Parser::condition()
{
}

bool Parser::sCondition()
{
}

bool Parser::tCondition()
{
}

bool Parser::conditional()
{
	std::cout << "conditional" << std::endl;
	return true;
}

bool Parser::agumentsDec()
{
}

bool Parser::procedureDeclaration()
{
}

bool Parser::loop()
{
	std::cout << "loop" << std::endl;
	return true;
}

bool Parser::val()
{
}
