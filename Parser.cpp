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
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std::cout << "InstructionList" <<std::endl;
	
	if(Instruction(currentAstNode)/* && InstructionList(currentAstNode)*/)
	{
		parent->AddChild(currentAstNode);
		return true;
	}
	else
	{
		
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::Instruction(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std::cout << "Instruction" <<std::endl;
	
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
	
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Assignment" << std::endl;
	
	if(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " ID_VARIABLE" << std::endl;
		isLexemeUsed = true;
		if(NextLexeme().GetCategory() == OP_ASSIGN)
		{
			
			for(unsigned int i = 0; i < depth; ++i)
			{
				std::cout << " ";
			}
			std:: cout << " OP_ASSIGN" << std::endl;
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
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Exp" << std::endl;
	
	if(SExp(currentAstNode))
	{
		if(AddOp(currentAstNode)) // optional
		{
			if(Exp(currentAstNode))
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
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "SExp" << std::endl;
	
	if(Factor(currentAstNode))
	{
		if(MultOp(currentAstNode)) // optional
		{
			if(SExp(currentAstNode))
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

bool Parser::Factor(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Factor" << std::endl;
	
	if(Val(currentAstNode))
	{
		parent->AddChild(currentAstNode);
		return true;
	} 
	else if (ProcedureCall(currentAstNode))
	{
		parent->AddChild(currentAstNode);
		return true;
	}
	else
	{
		if(NextLexeme().GetCategory() == OB_CBRACKET)
		{
			isLexemeUsed = true;
			
			for(unsigned int i = 0; i < depth; ++i)
			{
				std::cout << " ";
			}
			std:: cout << " OB_CBRACKET" << std::endl;
			if(Exp(currentAstNode))
			{
				if(NextLexeme().GetCategory() == CB_CBRACKET)
				{
					isLexemeUsed = true;
					for(unsigned int i = 0; i < depth; ++i)
					{
						std::cout << " ";
					}
					std:: cout << " CB_CBRACKET" << std::endl;
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
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "MultOp" << std::endl;
	
	if(NextLexeme().GetCategory() == OP_MULTIPLY)
	{
		isLexemeUsed = true;
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " OP_MULTIPLY" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	else if(NextLexeme().GetCategory() == OP_DEVIDE)
	{
		isLexemeUsed = true;
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " OP_DEVIDE" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}

bool Parser::AddOp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "AddOp" << std::endl;
	
	if(NextLexeme().GetCategory() == OP_PLUS)
	{
		isLexemeUsed = true;
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " OP_PLUS" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	else if(NextLexeme().GetCategory() == OP_MINUS)
	{
		isLexemeUsed = true;
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " OP_MINUS" << std::endl;
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
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "ProcedureCall" << std::endl;
	delete currentAstNode;
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
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = depthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Val" << std::endl;
	
	if(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		isLexemeUsed = true;
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " ID_VARIABLE" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	else if(NextLexeme().GetCategory() == VALUE)
	{
		isLexemeUsed = true;
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " VALUE" << std::endl;
		parent->AddChild(currentAstNode);
		return true;
	}
	
	delete currentAstNode;
	return false;
}

int Parser::depthCalculate(AstNode* astNode)
{
	int result = 0;
	
	AstNode* currentNode = astNode;
	while(currentNode->getParent() != nullptr)
	{
		++result;
		currentNode = currentNode->getParent();
	}
	
	return result;
}
