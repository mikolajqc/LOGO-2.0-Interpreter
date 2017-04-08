#ifndef LEXEME.H
#define LEXEME.H

#include "LexemeType.h"
#include "LexemeCategory.h"

class Lexeme
{
public:
	LexemeType GetType();
	void SetType(LexemeType lexemeType);
	
	LexemeCategory GetCategory();
	
	Lexeme(LexemeType lexemeType)
	:lexemeType(lexemeType) {};
	
private:
	LexemeType lexemeType;
	LexemeCategory lexemeCategory;
};

#endif //LEXEME.H