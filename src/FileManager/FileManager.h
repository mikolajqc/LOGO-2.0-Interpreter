#ifndef FILEMANAGER_H
#define FILEMANAGER_H 
#include <string>
#include <fstream>

class FileManager
{
public:
	FileManager (std::string filePath);
	~FileManager ();
	std::string GetNextWord();
	
private:
	std::string filePath;
	std::fstream fileStream;
	
	bool OpenFileStream();
	bool CloseFileStream(); 
	
	char GetNextChar();
};

#endif // FILEMANAGER_H