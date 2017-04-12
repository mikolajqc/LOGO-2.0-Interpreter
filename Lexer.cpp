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

Lexeme Lexer::CreateLexeme(std::string word)
{
	Lexeme resultLexeme;
	if(word.empty())
	{
		resultLexeme.SetCategory(EMPTY);
		return resultLexeme;
	}
	
	if(word == "FD" || word == "BK" || word == "RT" || word  == "LT")
	{
		resultLexeme.SetCategory(KW_MOVE);
		resultLexeme.SetValue(word);
		return resultLexeme;
	}
	else if(word == "REPEAT")
	{
		resultLexeme.SetCategory(KW_REPEAT);
		return resultLexeme;
	}
	else if(word == "TO")
	{
		resultLexeme.SetCategory(KW_TO);
		return resultLexeme;
	}
	else if(word == "END")
	{
		resultLexeme.SetCategory(KW_END);
		return resultLexeme;
	}
	else if(word == "PU" || word == "PD" || word =="CS")
	{
		resultLexeme.SetCategory(KW_SCREEN);
		resultLexeme.SetValue(word);
		return resultLexeme;
	}
	else if(word == "SETPC")
	{
		resultLexeme.SetCategory(KW_SETPC);
		return resultLexeme;
	}
	else if(word == "OUTPUT")
	{
		resultLexeme.SetCategory(KW_OUTPUT);
		return resultLexeme;
	}
	else if(word == "PRINT")
	{
		resultLexeme.SetCategory(KW_PRINT);
		return resultLexeme;
	}
	else if(word == "IF")
	{
		resultLexeme.SetCategory(KW_IF);
		return resultLexeme;
	}
	else if(word == "STOP")
	{
		resultLexeme.SetCategory(KW_STOP);
		return resultLexeme;
	}
	else if(word == "+")
	{
		resultLexeme.SetCategory(OP_PLUS);
		return resultLexeme;
	}
	else if(word == "-")
	{
		resultLexeme.SetCategory(OP_MINUS);
		return resultLexeme;
	}
	else if(word == "*")
	{
		resultLexeme.SetCategory(OP_MULTIPLY);
		return resultLexeme;
	}
	else if(word == "/")
	{
		resultLexeme.SetCategory(OP_DEVIDE);
		return resultLexeme;
	}
	else if(word == "&&")
	{
		resultLexeme.SetCategory(OP_AND);
		return resultLexeme;
	}
	else if(word =="||")
	{
		resultLexeme.SetCategory(OP_OR);
		return resultLexeme;
	}
	else if(word == "[")
	{
		resultLexeme.SetCategory(OB_SBRACKET);
		return resultLexeme;
	}
	else if(word == "]")
	{
		resultLexeme.SetCategory(CB_SBRACKET);
		return resultLexeme;
	}
	else if(word == "(")
	{
		resultLexeme.SetCategory(OB_CBRACKET);
		return resultLexeme;
	}
	else if(word == ")")
	{
		resultLexeme.SetCategory(CB_SBRACKET);
		return resultLexeme;
	}
	else if(word == "=")
	{
		resultLexeme.SetCategory(OP_ASSIGN);
		return resultLexeme;
	}
	else if(word =="==" || word == "!=" || word == ">" || word == ">=" || word == "<" || word == "<=")
	{
		resultLexeme.SetCategory(OP_COMPARISON);
		resultLexeme.SetValue(word); // change in docu
		return resultLexeme;
	}
	
	//ID_VARIABLE
	else if(word.front() == ':')
	{
		if(word.size() > 1 && (std::isalpha(word[1]) || word[1] == '_'))
		{
			for(unsigned int i = 2; i < word.size(); ++i)
			{
				if(!(std::isalnum(word[i]) || word[i] == '_'))
				{
					std::cout << "Error: Cannot recognize " << word << std::endl;
					resultLexeme.SetCategory(ERROR);
					return resultLexeme;
				}
			}
		}
		else
		{
			std::cout << "Error: Cannot recognize " << word << std::endl;
			resultLexeme.SetCategory(ERROR);
			return resultLexeme;
		}
		
		resultLexeme.SetCategory(ID_VARIABLE);
		word.erase(word.begin());
		resultLexeme.SetValue(word);
		return resultLexeme;
	}
	//id_procedure
	else if(std::isalpha(word.front()) || word.front() == '_')
	{

		for(unsigned int i = 1; i < word.size(); ++i)
		{
			if(!(std::isalnum(word[i]) || word[i] == '_'))
			{
				std::cout << "Error: Cannot recognize " << word << std::endl;
				resultLexeme.SetCategory(ERROR);
				return resultLexeme;
			}
		}
		
		resultLexeme.SetCategory(ID_PROCEDURE);
		resultLexeme.SetValue(word);
		return resultLexeme;
	}
	
	//value
	else if(std::isdigit(word.front()) || word.front() == '\"')
	{ 
		if(std::isdigit(word.front()))
		{
			for(unsigned int i = 1; i < word.size(); ++i)
			{
				if(!(std::isdigit(word[i])))
				{
					std::cout << "Error: Cannot recognize " << word << std::endl;
					resultLexeme.SetCategory(ERROR);
					return resultLexeme;
				}
			}
		}
		
		if(word.front() == '\"')
		{
			
			for(unsigned int i = 1; i < word.size() - 1; ++i)
			{
				if(word[i] == '\"')
				{
					std::cout << "Error: Cannot recognize" << word << std::endl;
					resultLexeme.SetCategory(ERROR);
					return resultLexeme;
				}
			}
			
			if(!(word.back() == '\"'))
			{
				std::cout << "Error: Cannot recognize" << word << std::endl;
				resultLexeme.SetCategory(ERROR);
				return resultLexeme;
			}
			word.erase(word.begin());
			word.erase(word.end() - 1);

		}
		resultLexeme.SetCategory(VALUE);
		resultLexeme.SetValue(word);
		return resultLexeme;
	}
	//error
	else
	{
		std::cout << "Error: Cannot recognize" << word << std::endl;
		resultLexeme.SetCategory(ERROR);
	}
	return resultLexeme;
}

std::string Lexer::GetNextWord()
{
	//this doesnt supports strings with spaces!
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
	
	while(!fileStream.eof() && (std::isgraph(currentChar) || (std::isprint(currentChar) && isString) ))
	{
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