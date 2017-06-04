#include "Parser.h"
#include "LexemeCategory.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "AddOpAstNode.h"
#include "AssignmentAstNode.h"
#include "InstructionAstNode.h"
#include "InstructionListAstNode.h"
#include "src/Parser/TempAstNode.h"
#include "ExpAstNode.h"
#include "SExpAstNode.h"
#include "FactorAstNode.h"
#include "MultOpAstNode.h"
#include "src/Parser/StartAstNode.h"
#include "src/Parser/LoopAstNode.h"
#include "src/Parser/ProcedureDeclarationAstNode.h"
#include "src/Parser/ArgumentsDecAstNode.h"
#include "src/Parser/ProcedureCallAstNode.h"
#include "src/Parser/ArgumentsAstNode.h"
#include "src/Parser/ConditionalAstNode.h"
#include "src/Parser/ConditionAstNode.h"
#include "src/Parser/SConditionAstNode.h"
#include "src/Parser/QConditionAstNode.h"
#include "src/Parser/TConditionAstNode.h"
#include "src/Parser/OutAstNode.h"
#include "ValAstNode.h"

class setArgumentName;
Parser::Parser(std::string path)
:isLexemeUsed(true), astTree(nullptr)
{
	lexer = new Lexer(path);
	executer = new Executer();
	window = new Window();
}

Parser::~Parser()
{
	delete lexer;
	delete astTree;
	delete executer;
	delete window;
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
	std::cout << "start" << std::endl;
	astTree = new StartAstNode(nullptr, window);
	
	if(InstructionList(astTree) == 2)
	{
		std::cout << "Parsing success!" << std::endl;
	}
	else
	{
		std::cout << "Parsing error!" << std::endl;
		exit(1);
	}
}

int Parser::InnerStart(AstNode* parent)
{
	//to jest tylko straznik. Nie jest on uwzgledniony w gramatyce!
	StartAstNode* currentAstNode = new StartAstNode(parent, window);
	
	if(InnerInstructionsList(currentAstNode) == 2)
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	else
	{
		delete currentAstNode;
		return 0;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::ArgumentsDecStart(AstNode* parent)
{
	//to jest tylko straznik. Nie jest on uwzgledniony w gramatyce!
	StartAstNode* currentAstNode = new StartAstNode(parent, window );
	
	while(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		ArgumentsDecAstNode* currentArgumentNode = new ArgumentsDecAstNode(currentAstNode, window);
		currentArgumentNode->setArgumentName(NextLexeme().GetValue());
		isLexemeUsed = true;
		
		currentAstNode->AddChild(currentArgumentNode);
	}

	parent->AddChild(currentAstNode);
	return 2;
}

int Parser::InstructionList(AstNode* parent)
{
	InstructionListAstNode* currentAstNode = new InstructionListAstNode(parent, window );
	int instructionResult = Instruction(currentAstNode);  /// to moze walic!!!
	int procedureResult  = ProcedureDeclaration(currentAstNode);  /// to tez
	
	if(instructionResult != 2 && procedureResult != 2)
	{
		delete currentAstNode;
		return 0;
	}
	
	while(instructionResult == 2 || procedureResult == 2)
	{
		instructionResult = Instruction(currentAstNode);
		procedureResult  = ProcedureDeclaration(currentAstNode);
		
		if(instructionResult == 0 && procedureResult == 0) 
		{
			delete currentAstNode;
			return 0;
		}
	}
	if(NextLexeme().GetCategory() == EMPTY) 
	{
		parent->AddChild(currentAstNode);
		return 2; // zwracamy 2 bo moze byc przypadek pusty! - zgodnie z gramatyka
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Instruction(AstNode* parent)
{
	InstructionAstNode* currentAstNode = new InstructionAstNode(parent,window);

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
	
	instructionResult = ProcedureCall(currentAstNode); //za tym nie mozna definiowac zmiennych!
	
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
	
	
	instructionResult = Out(currentAstNode);
	
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
	
	AssignmentAstNode* currentAstNode = new AssignmentAstNode(parent,window);

	if(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		currentAstNode->setNameOfVariable(NextLexeme().GetValue());

		isLexemeUsed = true;
		if(NextLexeme().GetCategory() == OP_ASSIGN)
		{
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
			exit(1);
		}
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Exp(AstNode* parent)
{
	ExpAstNode* currentAstNode = new ExpAstNode(parent,window);

	int sExpResult = SExp(currentAstNode);
	
	if(sExpResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	else if(sExpResult == 1)
	{
		delete currentAstNode;
		return 1;
	}
	else
	{
		while(AddOp(currentAstNode) == 2) // optional
		{
			if(SExp(currentAstNode) != 2)
			{
				delete currentAstNode; /// add op musi stac przed sexp!!!
				return 0;
			}
		}
		//jesli addop nierozpoznany to ok koniec exp
		parent->AddChild(currentAstNode);
		return 2;
	}
}

int Parser::SExp(AstNode* parent)
{
	SExpAstNode* currentAstNode = new SExpAstNode(parent,window);

	int factorResult = Factor(currentAstNode);
	
	if(factorResult == 0)
	{
		delete currentAstNode;
		return 0;
	}
	else if(factorResult == 1)
	{
		delete currentAstNode;
		return 1;
	}
	else
	{
		while(MultOp(currentAstNode) == 2) // optional
		{
			if(Factor(currentAstNode) != 2)
			{
				delete currentAstNode; /// mult op musi stac przed factor!!!
				return 0;
			}
		}
		//jesli addop nierozpoznany to ok koniec exp
		parent->AddChild(currentAstNode);
		return 2;
	}
	
}

int Parser::Factor(AstNode* parent)
{
	FactorAstNode* currentAstNode = new FactorAstNode(parent,window);

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

	if(NextLexeme().GetCategory() == OB_CBRACKET)
	{
		isLexemeUsed = true;

		if(Exp(currentAstNode) == 2)
		{
			if(NextLexeme().GetCategory() == CB_CBRACKET)
			{
				isLexemeUsed = true;

				parent->AddChild(currentAstNode);
				return 2;
			}
			else
			{
				std:: cout << ") was expected!\n";
				exit(1);
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
	MultOpAstNode* currentAstNode = new MultOpAstNode(parent,window);

	if(NextLexeme().GetCategory() == OP_MULTIPLY)
	{
		currentAstNode->setIsMult(true);
		isLexemeUsed = true;

		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(NextLexeme().GetCategory() == OP_DEVIDE)
	{
		currentAstNode->setIsMult(false);
		isLexemeUsed = true;

		parent->AddChild(currentAstNode);
		return 2;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::AddOp(AstNode* parent)
{
	AddOpAstNode* currentAstNode = new AddOpAstNode(parent,window);

	if(NextLexeme().GetCategory() == OP_PLUS)
	{
		currentAstNode->setIsPlus(true);
		isLexemeUsed = true;

		parent->AddChild(currentAstNode);
		return 2;
	}
	else if(NextLexeme().GetCategory() == OP_MINUS)
	{
		currentAstNode->setIsPlus(false);
		isLexemeUsed = true;

		parent->AddChild(currentAstNode);
		return 2;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Arguments(AstNode* parent)
{
	ArgumentsAstNode* currentAstNode = new ArgumentsAstNode(parent,window);

	int expResult = Exp(currentAstNode);
	
	while(expResult == 2)
	{
		expResult = Exp(currentAstNode);
	}
	if(expResult == 0)
	{
		delete currentAstNode;
		return 0;
	}

	parent->AddChild(currentAstNode);
	return 2;
}

int Parser::ProcedureCall(AstNode* parent)
{
	ProcedureCallAstNode* currentAstNode = new ProcedureCallAstNode(parent,window);

	if(NextLexeme().GetCategory() == ID_PROCEDURE)
	{
		currentAstNode->SetProcedureName(NextLexeme().GetValue());
		
		isLexemeUsed = true;
		
		if(NextLexeme().GetCategory() == OB_SBRACKET)
		{
			isLexemeUsed = true;
			
			if(Arguments(currentAstNode) == 2)
			{
				
				if(NextLexeme().GetCategory() == CB_SBRACKET)
				{
					isLexemeUsed = true;
					parent->AddChild(currentAstNode);
					return 2;
					
				}
				else
				{
					std::cout << "] was expected in procedure call!";
					delete currentAstNode;
					exit(1);//return 0;
				}
			}
			else
			{
				delete currentAstNode;
				return 0;
			}
			
		}
		else
		{
			std::cout << "[ was expected in procedure call!";
			delete currentAstNode;
			exit(1);//return 0;
		}
	}
	
	
	delete currentAstNode;
	return 1;
}

int Parser::Out(AstNode* parent)
{
	OutAstNode* currentAstNode = new OutAstNode(parent,window);

	if(NextLexeme().GetCategory() == KW_OUTPUT)
	{
		currentAstNode->SetOperation("OUTPUT");
		isLexemeUsed = true;
		
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
	
	if(NextLexeme().GetCategory() == KW_PRINT)
	{
		currentAstNode->SetOperation("PRINT");
		isLexemeUsed = true;
		
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
	
	if(NextLexeme().GetCategory() == KW_STOP)
	{
		currentAstNode->SetOperation("STOP");
		isLexemeUsed = true;
		
		parent->AddChild(currentAstNode);
		return 2;
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::Graphics(AstNode* parent)
{
	TempAstNode* currentAstNode = new TempAstNode(parent,window);
	
	if(NextLexeme().GetCategory() == KW_MOVE)
	{
		currentAstNode->SetOperation(NextLexeme().GetValue());
		isLexemeUsed = true;
		
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
	
	if(NextLexeme().GetCategory() == KW_SETPC)
	{
		currentAstNode->SetOperation(NextLexeme().GetValue());
		isLexemeUsed = true;
		
		if(NextLexeme().GetCategory() == OB_SBRACKET)
		{
			isLexemeUsed = true;
			
			if((Exp(currentAstNode) == 2)  && (Exp(currentAstNode) == 2) && (Exp(currentAstNode) == 2))
			{
				if(NextLexeme().GetCategory() == CB_SBRACKET)
				{
					isLexemeUsed = true;
					parent->AddChild(currentAstNode);
					return 2;
				}
				else
				{
					std::cout << "] was expected in SETPC call!";
					delete currentAstNode;
					exit(1);
				}
			}
			else
			{
				delete currentAstNode;
				return 0;
			}
		}
		else
		{
			std::cout << "[ was expected in SETPC call!";
			delete currentAstNode;
			exit(1);
		}
	}
	
	if(NextLexeme().GetCategory() == KW_SCREEN)
	{
		currentAstNode->SetOperation(NextLexeme().GetValue());
		isLexemeUsed = true;
		
		parent->AddChild(currentAstNode);
		return 2;
	}
	
	
	delete currentAstNode;
	return 1;
}

int Parser::InnerInstructionsList(AstNode* parent)
{
	InstructionListAstNode* currentAstNode = new InstructionListAstNode(parent,window);
	int instructionResult = Instruction(currentAstNode);
	
	while(instructionResult == 2)
	{
		instructionResult = Instruction(currentAstNode);
		if(instructionResult == 0) 
		{
			delete currentAstNode;
			return 0;
		}
	}
	if(NextLexeme().GetCategory() == KW_END || NextLexeme().GetCategory() == CB_SBRACKET) 
	{
		parent->AddChild(currentAstNode);
		return 2;
	}
	
	delete currentAstNode;
	return 1;
	
}

int Parser::Condition(AstNode* parent)
{
	ConditionAstNode* currentAstNode = new ConditionAstNode(parent,window);

	int sConditionResult = SCondition(currentAstNode);
	
	if(sConditionResult == 2)
	{
		if(NextLexeme().GetCategory() == OP_OR)
		{
			isLexemeUsed = true;
			
			if(Condition(currentAstNode) == 2)
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
		return 2; // zwracamy 2 bo moze byc przypadek pusty! - zgodnie z gramatyka
	}
	else if(sConditionResult == 0)
	{
		delete currentAstNode;
		return 0; //error bo instuction  rozpoznal ae otem wywola bllad
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::SCondition(AstNode* parent)
{
	SConditionAstNode* currentAstNode = new SConditionAstNode(parent,window);

	int qConditionResult = QCondition(currentAstNode);
	
	if(qConditionResult == 2)
	{
		if(NextLexeme().GetCategory() == OP_AND)
		{
			isLexemeUsed = true;
			
			if(SCondition(currentAstNode) == 2)
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
		return 2; // zwracamy 2 bo moze byc przypadek pusty! - zgodnie z gramatyka
	}
	else if(qConditionResult == 0)
	{
		delete currentAstNode;
		return 0; //error bo instuction  rozpoznal ae otem wywola bllad
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::QCondition(AstNode* parent)
{
	QConditionAstNode* currentAstNode = new QConditionAstNode(parent,window);

	int tConditionResult = TCondition(currentAstNode);
	
	if(tConditionResult == 2)
	{
		if(NextLexeme().GetCategory() == OP_COMPARISON)
		{
			currentAstNode->SetOperatorInString(NextLexeme().GetValue());
			
			isLexemeUsed = true;
			
			if(TCondition(currentAstNode) == 2)
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
		return 2; // zwracamy 2 bo moze byc przypadek pusty! - zgodnie z gramatyka
	}
	else if(tConditionResult == 0)
	{
		delete currentAstNode;
		return 0; //error bo instuction  rozpoznal ae otem wywola bllad
	}
	
	delete currentAstNode;
	return 1;
}

int Parser::TCondition(AstNode* parent)
{
	TConditionAstNode* currentAstNode = new TConditionAstNode(parent,window);

	if(NextLexeme().GetCategory() == OB_CBRACKET)
	{
		isLexemeUsed = true;
		
		if(Condition(currentAstNode) == 2)
		{
			if(NextLexeme().GetCategory() == CB_CBRACKET)
			{
				isLexemeUsed = true;
				
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
			delete currentAstNode;
			return 0; 
		}
	}
	
	//exp
	int expResult = Exp(currentAstNode);
	
	if(expResult == 2)
	{
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

int Parser::Conditional(AstNode* parent)
{
	ConditionalAstNode* currentAstNode = new ConditionalAstNode(parent,window);

	if(NextLexeme().GetCategory() == KW_IF)
	{
		isLexemeUsed = true;
		
		if(Condition(currentAstNode) == 2)
		{
			if(NextLexeme().GetCategory() == OB_SBRACKET)
			{
				isLexemeUsed = true;
				
				if(InnerStart(currentAstNode) == 2)
				{
					if(NextLexeme().GetCategory() == CB_SBRACKET)
					{
						isLexemeUsed = true;
						parent->AddChild(currentAstNode);
						return 2;
					}
					else
					{
						std::cout << "] was expected in IF call!";
						delete currentAstNode;
						exit(1);
					}
				}
				else
				{
					delete currentAstNode;
					return 0;
				}
			}
			else
			{
				std::cout << "[ was expected in IF body!";
				delete currentAstNode;
				exit(1);
			}
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

int Parser::ArgumentsDec(AstNode* parent)
{
	ArgumentsDecAstNode* currentAstNode = new ArgumentsDecAstNode(parent,window);

	while(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		currentAstNode->setArgumentName(NextLexeme().GetValue());
		isLexemeUsed = true;
		
		if(ArgumentsDec(currentAstNode) == 2)
		{
			
		}
		
		parent->AddChild(currentAstNode);
		return 2;
	}

	delete currentAstNode; ///ZROB TO TEZ W INNYCH MIEJSCACH !!!
	return 2;
}

int Parser::ProcedureDeclaration(AstNode* parent)
{
	ProcedureDeclarationAstNode* currentAstNode = new ProcedureDeclarationAstNode(parent,window);

	if(NextLexeme().GetCategory() == KW_TO)
	{
		isLexemeUsed = true;
		
		if(NextLexeme().GetCategory() == ID_PROCEDURE)
		{
			currentAstNode->SetProcedureName(NextLexeme().GetValue());
			isLexemeUsed = true;
			
			if(ArgumentsDecStart(currentAstNode) == 2)
			{
				
				if(NextLexeme().GetCategory() == OB_SBRACKET)
				{
					isLexemeUsed = true;
					///WE HAVE TO CHANGE GRAMATICS
					
					if(InnerStart(currentAstNode) == 2)
					{
						if(NextLexeme().GetCategory() == CB_SBRACKET)
						{
							isLexemeUsed = true;
							parent->AddChild(currentAstNode);
							return 2;
						}
					}
					else
					{
						std::cout << "] was expected in procedure declaration!\n";
						delete currentAstNode;
						exit(1);//return 0;
					}
					
				}
				else
				{
					std::cout << "[ was expected in procedure declaration!\n";
					delete currentAstNode;
					exit(1);//return 0;
				}
				
			}
			else
			{
				delete currentAstNode;
				return 0;
			}
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

int Parser::Loop(AstNode* parent)
{
	LoopAstNode* currentAstNode = new LoopAstNode(parent,window);
	
	if(NextLexeme().GetCategory() == KW_REPEAT)
	{
		isLexemeUsed = true;
		
		if(Exp(currentAstNode) == 2)
		{
			if(NextLexeme().GetCategory() == OB_SBRACKET)
			{
				isLexemeUsed = true;
				
				if(InnerStart(currentAstNode) == 2)
				{
					if(NextLexeme().GetCategory() == CB_SBRACKET)
					{
						isLexemeUsed = true;
						parent->AddChild(currentAstNode);
						return 2; 
					}
					else
					{
						std::cout << "] was expected in REPEAT body!";
						delete currentAstNode;
						exit(1);
					}
				}
				else
				{
					delete currentAstNode;
					return 0;
				}
			}
			else
			{
				std::cout << "[ was expected in REPEAT body!";
				delete currentAstNode;
				exit(1);
			}
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

int Parser::Val(AstNode* parent)
{
	ValAstNode* currentAstNode = new ValAstNode(parent,window);
	
	if(NextLexeme().GetCategory() == ID_VARIABLE)
	{
		currentAstNode->SetIsVariable(true);
		currentAstNode->SetValue(NextLexeme().GetValue());
		isLexemeUsed = true;

		parent->AddChild(currentAstNode);
		return 2; //everthing is ok
	}
	else if(NextLexeme().GetCategory() == VALUE)
	{
		currentAstNode->SetIsVariable(false);
		currentAstNode->SetValue(NextLexeme().GetValue());
		isLexemeUsed = true;
		parent->AddChild(currentAstNode);
		return 2;
	}
	
	delete currentAstNode;
	return 1; //i dont know what is it but i m not sure if it is an error
}

void Parser::execute()
{
	std::cout << "Executing\n";
	executer->AddContext();
	astTree->execute(executer);
	executer->DeleteContext();
	
	window->start();
	
}

void Parser::check()
{
	astTree->check();
}
