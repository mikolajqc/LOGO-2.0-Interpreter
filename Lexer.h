#ifndef  LEXER_H
#define  LEXER_H
#include <fstream>
#include <string>
#include <locale>
#include <iostream>
#include "Lexeme.h"

class Lexer
{
public:
	Lexeme NextLexeme();
	
	Lexer(std::string filePath);
	~Lexer();
private:
	std::string filePath;
	std::fstream fileStream;
	
	bool OpenFileStream();
	bool CloseFileStream();
	
	char GetNextChar();
	std::string GetNextWord();
	Lexeme CreateLexeme(std::string word);
};

#endif //LEXER_H