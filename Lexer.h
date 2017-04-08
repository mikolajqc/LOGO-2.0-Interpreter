#ifndef  LEXER.H
#define LEXER.H

#include <fstream>
#include <string>
#include <locale>
#include <iostream> // do usuniecia
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

#endif //LEXER.H