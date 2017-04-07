#ifndef  LEXEMETYPE.H
#define LEXEMETYPE.H


enum LexemeType
{
	FD,	//|
	BK,	//|
	RT,	//|--KW_MOVE
	LT,	//|
	
	PU,
	PD,	//|--KW_SCREEN
	CS,
	
	EQUAL,
	NOT_EQUAL,
	MORE,
	MORE_EQUAL,		//|--OP_COMPARISON
	LESS,
	LESS_EQUAL,
	
	STRING,
	FLOAT,			//|--VALUE, ID_PROCEDURE or ID_VARIABLE
	INT,
	
	EMPTY
};


#endif //LEXEMETYPE.H