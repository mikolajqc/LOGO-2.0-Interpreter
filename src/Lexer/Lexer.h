#ifndef  LEXER_H
#define  LEXER_H
#include <fstream>
#include <string>
#include <locale>
#include <iostream>
#include "Lexeme.h"
#include "src/FileManager/FileManager.h"

class Lexer
{
public:
	Lexeme NextLexeme();
	
	Lexer(std::string filePath);
	~Lexer();
private:
	FileManager* fileManager;
	Lexeme CreateLexeme(std::string word);
};

#endif //LEXER_H