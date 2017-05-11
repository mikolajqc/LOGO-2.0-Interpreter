#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser
{
public:
	Parser();
	~Parser();
	
	bool start();

private:
	Lexer* lexer;
	Lexeme currentLexeme;
	
	void setCurrentLexeme();
	
	//funkcje rozbioru:
	
	bool instructionList();
	bool instruction();
	
	bool assignment();
	bool exp();
	bool sExp();
	bool factor();
	bool multOp();
	bool addOp();
	bool arguments();
	bool procedureCall();
	bool out();
	bool graphics();
	bool innerInstructionsList();
	bool condition();
	bool sCondition();
	bool tCondition();
	bool conditional();
	bool agumentsDec();
	bool procedureDeclaration();
	bool loop();
	bool val();
	
	

};

#endif // PARSER_H
