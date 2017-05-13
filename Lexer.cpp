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
	fileStream.close(); 
	return !fileStream.is_open();
}

char Lexer::GetNextChar()
{
	char result;
	fileStream.get(result);
	return result;
}

Lexeme Lexer::CreateLexeme(std::string word)
{
	//std::cout << word << " ";
	Lexeme resultLexeme;
	if(word.empty())
	{
		resultLexeme.SetCategory(EMPTY);
	}else if(word == "FD" || word == "BK" || word == "RT" || word  == "LT")
	{
		resultLexeme.SetCategory(KW_MOVE);
		resultLexeme.SetValue(word);
	}
	else if(word == "REPEAT")
	{
		resultLexeme.SetCategory(KW_REPEAT);
	}
	else if(word == "TO")
	{
		resultLexeme.SetCategory(KW_TO);
	}
	else if(word == "END")
	{
		resultLexeme.SetCategory(KW_END);
	}
	else if(word == "PU" || word == "PD" || word =="CS")
	{
		resultLexeme.SetCategory(KW_SCREEN);
		resultLexeme.SetValue(word);
	}
	else if(word == "SETPC")
	{
		resultLexeme.SetCategory(KW_SETPC);
	}
	else if(word == "OUTPUT")
	{
		resultLexeme.SetCategory(KW_OUTPUT);
	}
	else if(word == "PRINT")
	{
		resultLexeme.SetCategory(KW_PRINT);
	}
	else if(word == "IF")
	{
		resultLexeme.SetCategory(KW_IF);
	}
	else if(word == "STOP")
	{
		resultLexeme.SetCategory(KW_STOP);
	}
	else if(word == "+")
	{
		resultLexeme.SetCategory(OP_PLUS);
	}
	else if(word == "-")
	{
		resultLexeme.SetCategory(OP_MINUS);
	}
	else if(word == "*")
	{
		resultLexeme.SetCategory(OP_MULTIPLY);
	}
	else if(word == "/")
	{
		resultLexeme.SetCategory(OP_DEVIDE);
	}
	else if(word == "&&")
	{
		resultLexeme.SetCategory(OP_AND);
	}
	else if(word =="||")
	{
		resultLexeme.SetCategory(OP_OR);
	}
	else if(word == "[")
	{
		resultLexeme.SetCategory(OB_SBRACKET);
	}
	else if(word == "]")
	{
		resultLexeme.SetCategory(CB_SBRACKET);
	}
	else if(word == "(")
	{
		resultLexeme.SetCategory(OB_CBRACKET);
	}
	else if(word == ")")
	{
		resultLexeme.SetCategory(CB_CBRACKET);
	}
	else if(word == "=")
	{
		resultLexeme.SetCategory(OP_ASSIGN);
	}
	else if(word =="==" || word == "!=" || word == ">" || word == ">=" || word == "<" || word == "<=")
	{
		resultLexeme.SetCategory(OP_COMPARISON);
		resultLexeme.SetValue(word); // change in docu
	}
	//ID_VARIABLE
	else if(word.front() == ':')
	{
		if(word.size() > 1 && (std::isalpha(word[1]) || word[1] == '_'))
		{
			resultLexeme.SetCategory(ID_VARIABLE);
			
			for(unsigned int i = 2; i < word.size(); ++i)
			{
				if(!(std::isalnum(word[i]) || word[i] == '_'))
				{
					std::cout << "Error: Cannot recognize: " << word << std::endl;
					resultLexeme.SetCategory(ERROR);
					break;
				}
			}
			
			word.erase(word.begin());
			resultLexeme.SetValue(word);
			
		}
		else
		{
			std::cout << "Error: Cannot recognize: " << word << std::endl;
			resultLexeme.SetCategory(ERROR);
		}
	}
	//id_procedure
	else if(std::isalpha(word.front()) || word.front() == '_')
	{

		resultLexeme.SetCategory(ID_PROCEDURE);
		resultLexeme.SetValue(word);
		
		for(unsigned int i = 1; i < word.size(); ++i)
		{
			if(!(std::isalnum(word[i]) || word[i] == '_'))
			{
				std::cout << "Error: Cannot recognize: " << word << std::endl;
				resultLexeme.SetCategory(ERROR);
				break;
			}
		}
		
	}
	//value
	else if(std::isdigit(word.front()) || word.front() == '\"')
	{ 
		resultLexeme.SetCategory(VALUE);
		resultLexeme.SetValue(word);

		//int
		if(std::isdigit(word.front()))
		{
			for(unsigned int i = 1; i < word.size(); ++i)
			{
				if(!(std::isdigit(word[i])))
				{
					std::cout << "Error: Cannot recognize: " << word << std::endl;
					resultLexeme.SetCategory(ERROR);
					break;
				}
			}
		}
		
		//string
		if(word.front() == '\"')
		{
			for(unsigned int i = 1; i < word.size() - 1; ++i)
			{
				if(word[i] == '\"')
				{
					std::cout << "Error: Cannot recognize: " << word << std::endl;
					resultLexeme.SetCategory(ERROR);
					break;
				}
			}
			
			if(!(word.back() == '\"'))
			{
				std::cout << "Error: Cannot recognize: " << word << std::endl;
				resultLexeme.SetCategory(ERROR);
			}
			
			word.erase(word.begin());
			word.erase(word.end() - 1);
		}
	}
	//error
	else
	{
		std::cout << "Error: Cannot recognize: " << word << std::endl;
		resultLexeme.SetCategory(ERROR);
	}
	
	return resultLexeme;
}

std::string Lexer::GetNextWord()
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

Lexeme Lexer::NextLexeme()
{
	Lexeme lexeme = CreateLexeme(GetNextWord());
	return lexeme;
}