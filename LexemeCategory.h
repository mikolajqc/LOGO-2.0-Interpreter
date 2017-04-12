#ifndef LEXEMECATEGORY.H
#define LEXEMECATEGORY.H


enum LexemeCategory
{
	KW_MOVE,
	KW_REPEAT,
	KW_TO,
	KW_END,
	KW_SCREEN,
	KW_SETPC,// popraw w doku
	KW_OUTPUT,
	KW_PRINT,
	KW_IF,
	KW_STOP,
	OP_PLUS,
	OP_MINUS,
	OP_MULTIPLY,
	OP_DEVIDE,
	OP_AND,
	OP_OR,
	OB_SBRACKET,
	OB_CBRACKET,
	CB_SBRACKET,
	CB_CBRACKET,
	OP_ASSIGN,
	OP_COMPARISON,
	ID_PROCEDURE,
	ID_VARIABLE,
	VALUE,
	
	ERROR,
	EMPTY
};


#endif //LEXEMECATEGORY.H