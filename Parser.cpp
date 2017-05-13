#include "Parser.h"
#include "LexemeCategory.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


Parser::Parser()
:isLexemeUsed(true), astTree(nullptr)
{
	lexer = new Lexer("test.txt");
}

Parser::~Parser()
{
	delete lexer;
	delete astTree;
}

Lexeme Parser::NextLexeme()
{
	if(isLexemeUsed)
	{
		isLexemeUsed = false;
		currentLexeme = lexer->NextLexeme();
	}
	
	return currentLexeme;
}

void Parser::start()
{
	astTree = new AstNode(nullptr);
	std::cout << "start" << std::endl;
	if(InstructionList(astTree))
	{
		std::cout << "success!" << std::endl;
	}
	else
	{
		std::cout << "error!" << std::endl;
	}
}

bool Parser::InstructionList(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	if(Instruction(currentAstNode)/* && InstructionList(currentAstNode)*/)
	{
		parent->AddChild(currentAstNode);
		return true;
	}
	else
	{
		delete currentAstNode;
	}
	
	return true;
}

bool Parser::Instruction(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	if(Assignment(parent))
	{
		parent->AddChild(currentAstNode);
		return true;
	}
	delete currentAstNode;
	return false;// kiedys kiedy jest EOF trzeba zwrocic false;
}

bool Parser::Assignment(AstNode* parent)
{
	std:: cout << "Assignment" << std::endl;
	AstNode* currentAstNode = new AstNode(parent);
	
	if(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		std:: cout << "ID_VARIABLE" << std::endl;
		isLexemeUsed = true;
		if(NextLexeme().GetCategory() == OP_ASSIGN)
		{
			isLexemeUsed = true;
			
			if(Exp(currentAstNode))
			{
				//TODO exp();
				parent->AddChild(currentAstNode);
				return true;
			}
			
		}
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::Exp(AstNode* parent)
{
	std:: cout << "Exp" << std::endl;
	AstNode* currentAstNode = new AstNode(parent);
	if(SExp(parent))
	{
		if(AddOp(parent)) // optional
		{
			if(Exp(parent))
			{
				parent->AddChild(currentAstNode);
				return true;
			}
			else
			{
				delete currentAstNode;
				return false;
			}
		}
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::SExp(AstNode* parent)
{
	std:: cout << "SExp" << std::endl;
	AstNode* currentAstNode = new AstNode(parent);
	if(Factor(parent))
	{
		//if(MultOp(parent)) // optional
		//{
			//s_exp
			
		//}
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::Factor(AstNode* parent)
{
	std:: cout << "Factor" << std::endl;
	AstNode* currentAstNode = new AstNode(parent);
	
	if(Val(parent))
	{
		parent->AddChild(currentAstNode);
		return true;
	} 
	else if (ProcedureCall(parent))
	{
		parent->AddChild(currentAstNode);
		return true;
	}
	else
	{
		if(NextLexeme().GetCategory() == OB_CBRACKET)
		{
			isLexemeUsed = true;
			std:: cout << "OB_CBRACKET" << std::endl;
			if(Exp(parent))
			{
				if(NextLexeme().GetCategory() == CB_CBRACKET)
				{
					isLexemeUsed = true;
					std:: cout << "CB_CBRACKET" << std::endl;
					parent->AddChild(currentAstNode);
					return true;
				}
			}
			
		}
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::MultOp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	std:: cout << "MultOp" << std::endl;
	
	if(NextLexeme().GetCategory() == OP_MULTIPLY)
	{
		isLexemeUsed = true;
		std:: cout << "OP_MULTIPLY" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	else if(NextLexeme().GetCategory() == OP_DEVIDE)
	{
		isLexemeUsed = true;
		std:: cout << "OP_DEVIDE" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::AddOp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	std:: cout << "MultOp" << std::endl;
	
	if(NextLexeme().GetCategory() == OP_PLUS)
	{
		isLexemeUsed = true;
		std:: cout << "OP_PLUS" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	else if(NextLexeme().GetCategory() == OP_MINUS)
	{
		isLexemeUsed = true;
		std:: cout << "OP_MINUS" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::Arguments(AstNode* parent)
{
	std:: cout << "Arguments" << std::endl;
	return false;
}

bool Parser::ProcedureCall(AstNode* parent)
{
	std:: cout << "ProcedureCall" << std::endl;
	return false;
}

bool Parser::Out(AstNode* parent)
{
	std:: cout << "Out" << std::endl;
	return false;
}

bool Parser::Graphics(AstNode* parent)
{
	std:: cout << "Graphics" << std::endl;
	return false;
}

bool Parser::InnerInstructionsList(AstNode* parent)
{
	std:: cout << "InnerInsrucionsList" << std::endl;
	return false;
}

bool Parser::Condition(AstNode* parent)
{
	std:: cout << "Condition" << std::endl;
	return false;
}

bool Parser::SCondition(AstNode* parent)
{
	std:: cout << "SCondition" << std::endl;
	return false;
}

bool Parser::TCondition(AstNode* parent)
{
	std:: cout << "TCondition" << std::endl;
	return false;
}

bool Parser::Conditional(AstNode* parent)
{
	std:: cout << "Conditional" << std::endl;
	return false;
}

bool Parser::AgumentsDec(AstNode* parent)
{
	std:: cout << "ArgumentsDec" << std::endl;
	return false;
}

bool Parser::ProcedureDeclaration(AstNode* parent)
{
	std:: cout << "ProcedureDeclaration" << std::endl;
	return false;
}

bool Parser::Loop(AstNode* parent)
{
	std:: cout << "Loop" << std::endl;
	return false;
}

bool Parser::Val(AstNode* parent)
{
	std:: cout << "Val" << std::endl;
	AstNode* currentAstNode = new AstNode(parent);
	
	if(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		isLexemeUsed = true;
		std:: cout << "ID_VARIABLE" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	else if(NextLexeme().GetCategory() == VALUE)
	{
		isLexemeUsed = true;
		std:: cout << "VALUE" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}
