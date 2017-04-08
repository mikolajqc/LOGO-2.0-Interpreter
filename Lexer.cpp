#include <Lexer.h>

Lexer::Lexer(std::string filePath)
{
	this->filePath = filePath;
	if(!OpenFileStream())
	{
		printf("Error: No such file directory!");
	}
}

Lexer::~Lexer()
{
	CloseFileStream();
}

bool Lexer::OpenFileStream()
{
	fileStream.open(filePath.c_str(), std::fstream::in);
	return fileStream.is_open();
}


bool Lexer::CloseFileStream()
{
	fileStream.close(); // it can be in destructor
	return !fileStream.is_open();
}

char Lexer::GetNextChar()
{
	char result;
	fileStream.get(result);
	return result;
}

std::string Lexer::GetNextWord()
{
	std::string result;
	char currentChar;
	
	do
	{
		currentChar = fileStream.get();
	}
	while(!fileStream.eof() && std::isspace(currentChar));
	
	while(!fileStream.eof() && std::isgraph(currentChar))
	{
		result.push_back(currentChar);
		fileStream.get(currentChar);
	}
	
	return result;
}

Lexeme Lexer::NextLexeme()
{
	Lexeme lexeme(EMPTY);
	
	std::cout << GetNextWord() << std::endl;
	std::cout << GetNextWord() << std::endl;
	
	return lexeme;
}