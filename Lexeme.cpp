#include "Lexeme.h"

std::string Lexeme::GetValue()
{
	return value;
}

void Lexeme::SetValue(std::string value)
{
	this->value = value;
}

LexemeCategory Lexeme::GetCategory()
{
	return lexemeCategory;
}

void Lexeme::SetCategory(LexemeCategory lexemeCategory)
{
	this->lexemeCategory = lexemeCategory;
}