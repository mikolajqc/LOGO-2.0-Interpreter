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
	if(InstructionList(astTree) == 2)
	{
		std::cout << "succes!" << std::endl;
	}
	else
	{
		std::cout << "error!" << std::endl;
	}
}

int Parser::InstructionList(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	WritePrefix(currentAstNode);
	std::cout << "InstructionList" <<std::endl;
	
	int instructionResult = Instruction(currentAstNode);
	if(instructionResult == 2)
	{
		if(InstructionList(currentAstNode) == 2)
		{
			parent->AddChild(currentAstNode);
			return 2;
		}
		else
		{
			delete currentAstNode;
			return 0; // im sure that here is an error intructin list 0 or 1
		}

	}
	else if(instructionResult == 0)
	{
		delete currentAstNode;
		return 0; //error bo instuction  rozpoznal ae otem wywola bllad
	}
	
	//instruction == 1 nie wie co zrobic zatem proba rozpoznania przez procedure declaration
	int procedureDeclarationResult = ProcedureDeclaration(currentAstNode);
	
	if(procedureDeclarationResult == 2) //instrctinresult 1
	{
		if(InstructionList(currentAstNode) == 2)
		{
			WritePrefix(currentAstNode);
			parent->AddChild(currentAstNode);
			return 2;
		}
		else
		{
			delete currentAstNode;
			return 0;
		}
	}
	else if(procedureDeclarationResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	
	//spawdzamy czy na koncu pliku
	if(NextLexeme().GetCategory() == EMPTY) 
	{
		delete currentAstNode;
		return 2; // zwracamy 2 bo moze byc przypadek pusty! - zgodnie z gramatyka
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Instruction(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std::cout << "Instruction" <<std::endl;
	
	int instructionResult = Assignment(currentAstNode);
	
	if(instructionResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(instructionResult == 0) // error
	{
		delete currentAstNode;
		return 0;
	}
	
	instructionResult = ProcedureCall(currentAstNode);
	
	if(instructionResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(instructionResult == 0) // error
	{
		delete currentAstNode;
		return 0;
	}
	
	instructionResult = Conditional(currentAstNode);
	
	if(instructionResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(instructionResult == 0) // error
	{
		delete currentAstNode;
		return 0;
	}
	
	instructionResult = Loop(currentAstNode);
	
	if(instructionResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(instructionResult == 0) // error
	{
		delete currentAstNode;
		return 0;
	}
	
	instructionResult = Graphics(currentAstNode);
	
	if(instructionResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(instructionResult == 0) // error
	{
		delete currentAstNode;
		return 0;
	}
	
	
	delete currentAstNode;
	return 1;// kiedys kiedy jest EOF trzeba zwrocic false;
}

int Parser::Assignment(AstNode* parent)
{
	
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
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
			
			if(Exp(currentAstNode) == 2)
			{
				//TODO exp();
				parent->AddChild(currentAstNode);
				return 2;
			}
			else
			{
				delete currentAstNode;
				return 0;
			}
			
		}
		else
		{
			std::cout << "= operator expected!\n";
			delete currentAstNode;
			return 0;
		}
	}

	//std::cout << "I wanted :sth";
	
	delete currentAstNode;
	return 1;
}

int Parser::Exp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Exp" << std::endl;
	
	int sExpResult = SExp(currentAstNode);
	
	if(sExpResult == 2) //rozpoznalismy sexp
	{
		if(AddOp(currentAstNode) == 2) // optional
		{
			if(Exp(currentAstNode) == 2)
			{
				parent->AddChild(currentAstNode);
				return 2;
			}
			else
			{
				delete currentAstNode;
				return 0;
			}
		}
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(sExpResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	
	//nie rozpoznalem
	delete currentAstNode;
	return 1;
}

int Parser::SExp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "SExp" << std::endl;
	
	int factorResult = Factor(currentAstNode);
	
	if(factorResult == 2)
	{
		if(MultOp(currentAstNode) == 2) // optional
		{
			if(SExp(currentAstNode) == 2)
			{
				parent->AddChild(currentAstNode);
				return 2;
			}
			else
			{
				delete currentAstNode;
				return 0;
			}
		}
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(factorResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Factor(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Factor" << std::endl;
	
	int valResult = Val(currentAstNode);
	
	if(valResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(valResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	
	//valResult == 1
	
	int procedureCallResult = ProcedureCall(currentAstNode);
	
	if (procedureCallResult == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(procedureCallResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	
	//procedureCallResult = 1
	
	if(NextLexeme().GetCategory() == OB_CBRACKET)
	{
		isLexemeUsed = true;
		
		for(unsigned int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}
		std:: cout << " OB_CBRACKET" << std::endl;
		
		if(Exp(currentAstNode) == 2)
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
				return 2;
			}
			else
			{
				std:: cout << ") was expected!\n";
				delete currentAstNode;
				return 0; //nieistotne czy nie rozpoznal exp czy blad w exp
			}
		}
		else
		{
			delete currentAstNode;
			return 0; //nieistotne czy nie rozpoznal exp czy blad w exp
		}
		
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::MultOp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
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
		return 2;
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
		return 2;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::AddOp(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
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
		return 2;
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
		return 2;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Arguments(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Arguments" << std::endl;
	
	int expResult = Exp(currentAstNode);
	
	if(expResult == 2)
	{
		Arguments(currentAstNode);
		
		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(expResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::ProcedureCall(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "ProcedureCall" << std::endl;
	
	if(NextLexeme().GetCategory() == ID_PROCEDURE)
	{
		isLexemeUsed = true;
		
		if(Arguments(currentAstNode) == 2)
		{
			parent->AddChild(currentAstNode);
			return 2;
		}
		else
		{
			delete currentAstNode;
			return 0;
		}
	}
	
	
	delete currentAstNode;
	return 1;
}

int Parser::Out(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "Out" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::Graphics(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	
	std:: cout << "Graphics" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::InnerInstructionsList(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	
	std:: cout << "InnerInsrucionsList" << std::endl;
	return 1;
}

int Parser::Condition(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	WritePrefix(currentAstNode);
	
	std:: cout << "Condition" << std::endl;
	delete currentAstNode;
	return 1;
}

int Parser::SCondition(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	WritePrefix(currentAstNode);
	
	std:: cout << "SCondition" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::TCondition(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	WritePrefix(currentAstNode);
	
	std:: cout << "TCondition" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::Conditional(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	WritePrefix(currentAstNode);
	
	std:: cout << "Conditional" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::AgumentsDec(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	WritePrefix(currentAstNode);
	
	std:: cout << "ArgumentsDec" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::ProcedureDeclaration(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
	std:: cout << "ProcedureDeclaration" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::Loop(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	WritePrefix(currentAstNode);
	
	std:: cout << "Loop" << std::endl;
	
	delete currentAstNode;
	return 1;
}

int Parser::Val(AstNode* parent)
{
	AstNode* currentAstNode = new AstNode(parent);
	
	unsigned int depth = DepthCalculate(currentAstNode);
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
		return 2; //everthing is ok
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
		return 2;
	}
	
	delete currentAstNode;
	return 1; //i dont know what is it but i m not sure if it is an error
}

int Parser::DepthCalculate(AstNode* astNode)
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

void Parser::WritePrefix(AstNode* astNode)
{
	unsigned int depth = DepthCalculate(astNode);
	for(unsigned int i = 0; i < depth; ++i)
	{
		std::cout << " ";
	}
}
