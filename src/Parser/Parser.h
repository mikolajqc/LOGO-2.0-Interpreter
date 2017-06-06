#ifndef PARSER_H
#define PARSER_H

#include "src/Lexer/Lexer.h"
#include "src/Parser/AstTree/AstNode.h"
#include "src/Window/Window.h"

class AstNode;

class Parser
{
public:
	Parser(std::string path);
	~Parser();
	
	void start();
	void execute();
	void check();
	
private:
	Lexer* lexer;
	Executer* executer;
	
	Window* window;
	
	Lexeme currentLexeme;
	bool isLexemeUsed;
	Lexeme NextLexeme();
	AstNode* astTree;
	
	///3 values: 0 - error, 1 - not recognize, 2 - success
	int ArgumentsDecStart(AstNode* parent);
	int InnerStart(AstNode* parent);
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
	int QCondition(AstNode* parent);
	int TCondition(AstNode* parent);
	int Conditional(AstNode* parent);
	int ArgumentsDec(AstNode* parent);
	int ProcedureDeclaration(AstNode* parent);
	int Loop(AstNode* parent);
	int Val(AstNode* parent);
	
};

#endif // PARSER_H
