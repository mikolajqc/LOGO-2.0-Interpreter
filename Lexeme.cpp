#include "Lexeme.h"

LexemeType Lexeme::GetType()
{
	return lexemeType;
}

void Lexeme::SetType(LexemeType lexemeType)
{
	this->lexemeType = lexemeType;
}

LexemeCategory Lexeme::GetCategory()
{
	return lexemeCategory;
}