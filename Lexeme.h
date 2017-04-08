#ifndef LEXEME.H
#define LEXEME.H

#include "LexemeType.h"
#include "LexemeCategory.h"
#include <string>

class Lexeme
{
public:
	std::string GetValue();
	void SetValue(std::string value);
	
	LexemeCategory GetCategory();
	void SetCategory(LexemeCategory lexemeCategory);
	
	//Lexeme(LexemeType lexemeType)
	//:lexemeType(lexemeType) {};
	
private:
	//LexemeType lexemeType;
	LexemeCategory lexemeCategory;
	std::string value;
};

#endif //LEXEME.H