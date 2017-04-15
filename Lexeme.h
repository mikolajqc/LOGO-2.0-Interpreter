#ifndef LEXEME_H
#define LEXEME_H 
#include "LexemeCategory.h"
#include <string>

class Lexeme
{
public:
	std::string GetValue();
	void SetValue(std::string value);
	
	LexemeCategory GetCategory();
	void SetCategory(LexemeCategory lexemeCategory);
	
private:
	LexemeCategory lexemeCategory;
	std::string value;
};

#endif //LEXEME_H