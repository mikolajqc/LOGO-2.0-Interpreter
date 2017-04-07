#ifndef LEXEME.H
#define LEXEME.H

#include "LexemeType.h"
#include "LexemeCategory.h"

class Lexeme
{
public:
	LexemeType GetType();
	LexemeType SetType();
	
	Lexeme(LexemeType lexemeType);
	
private:
	LexemeType lexemeType;
	LexemeCategory lexemeCategory;
};

#endif //LEXEME.H