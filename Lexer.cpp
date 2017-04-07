#include <Lexer.h>

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

bool Lexer::GetNextWord(std::string& newWord)
{
	char readedCharacter;
	
	if(fileStream.eof())
	{
		return false;
	}
	
	do
	{
		fileStream.get(readedCharacter);
	}
	while(!fileStream.eof() && std::isspace(readedCharacter));
	
	while(!fileStream.eof() && std::isgraph(readedCharacter))
	{
		newWord.push_back(readedCharacter);
		fileStream.get(readedCharacter);
	}
	
	return true;
}

Lexeme Lexer::NextLexeme()
{
	Lexeme lexeme(EMPTY);
	if(!OpenFileStream())
	{
		printf("Error: No such file directory!");
	}
	
	std::string word;
	if(GetNextWord(word) == false)
	{
		printf("Error: Cannot get next word!");
	}
	std::cout << word;
	
	CloseFileStream();
	return lexeme;
}