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
	bool InstructionList(AstNode* parent);
	bool Instruction(AstNode* parent);
	bool Assignment(AstNode* parent);
	bool Exp(AstNode* parent);
	bool SExp(AstNode* parent);
	bool Factor(AstNode* parent);
	bool MultOp(AstNode* parent);
	bool AddOp(AstNode* parent);
	bool Arguments(AstNode* parent);
	bool ProcedureCall(AstNode* parent);
	bool Out(AstNode* parent);
	bool Graphics(AstNode* parent);
	bool InnerInstructionsList(AstNode* parent);
	bool Condition(AstNode* parent);
	bool SCondition(AstNode* parent);
	bool TCondition(AstNode* parent);
	bool Conditional(AstNode* parent);
	bool AgumentsDec(AstNode* parent);
	bool ProcedureDeclaration(AstNode* parent);
	bool Loop(AstNode* parent);
	bool Val(AstNode* parent);
	
	//For Debug only:
	int DepthCalculate(AstNode* astNode);
	void WritePrefix(AstNode* astNode);
	
};

#endif // PARSER_H
