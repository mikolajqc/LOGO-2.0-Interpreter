#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "AstNode.h"

class Parser
{
public:
	Parser();
	~Parser();
	void start();
	
private:
	Lexer* lexer;
	Lexeme currentLexeme;
	bool isLexemeUsed;
	Lexeme NextLexeme();
	
	AstNode* astTree;
	
	//funkcje rozbioru:
	///3 values: 0 - error, 1 - not recognize, 2 - success
	int InstructionList(AstNode* parent);
	int Instruction(AstNode* parent);
	int Assignment(AstNode* parent);
	int Exp(AstNode* parent);
	int SExp(AstNode* parent);
	int Factor(AstNode* parent);
	int MultOp(AstNode* parent);
	int AddOp(AstNode* parent);
	int Arguments(AstNode* parent);
	int ProcedureCall(AstNode* parent);
	int Out(AstNode* parent);
	int Graphics(AstNode* parent);
	int InnerInstructionsList(AstNode* parent);
	int Condition(AstNode* parent);
	int SCondition(AstNode* parent);
	int TCondition(AstNode* parent);
	int Conditional(AstNode* parent);
	int ArgumentsDec(AstNode* parent);
	int ProcedureDeclaration(AstNode* parent);
	int Loop(AstNode* parent);
	int Val(AstNode* parent);
	
	//For Debug only:
	int DepthCalculate(AstNode* astNode);
	void WritePrefix(AstNode* astNode);
	
};

#endif // PARSER_H
