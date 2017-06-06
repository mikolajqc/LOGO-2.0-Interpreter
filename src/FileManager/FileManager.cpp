#include "FileManager.h"


FileManager::FileManager(std::string filePath)
{
	this->filePath = filePath;
	if(!OpenFileStream())
	{
		printf("Error: No such file directory!");
	}
}


FileManager::~FileManager()
{
	CloseFileStream();
}

bool FileManager::OpenFileStream()
{
	fileStream.open(filePath.c_str(), std::fstream::in);
	return fileStream.is_open();
}

bool FileManager::CloseFileStream()
{
	fileStream.close(); 
	return !fileStream.is_open();
}

char FileManager::GetNextChar()
{
	char result;
	fileStream.get(result);
	return result;
}

std::string FileManager::GetNextWord()
{
	std::string result;
	char currentChar;
	bool isString = false;
	
	do
	{
		currentChar = fileStream.get();
	}
	while(!fileStream.eof() && std::isspace(currentChar));
	
	if(currentChar == '\"')
	{
		isString = true;
	}
	
	if(currentChar == '(' || currentChar == '[' || currentChar == ')' || currentChar == ']')
	{
		result.push_back(currentChar);
		return result;
	}
	
	while(!fileStream.eof() && (std::isgraph(currentChar) || (std::isprint(currentChar) && isString) ))
	{
		if(currentChar == '(' || currentChar == '[' || currentChar == ')' || currentChar == ']')
		{
			//taking file pointer back
			fileStream.seekg (fileStream.tellg() - (std::streampos)1);
			break;
		}
		
		result.push_back(currentChar);
		fileStream.get(currentChar);
		if(isString && currentChar == '\"') isString = false;
	}
	
	return result;
}
