#pragma once
#include "Token.h"
#include "Code.h"

class Parser
{
public:
	Parser();
	~Parser();
	Code* ParseCode(Dictionary* Memory, int* Limit);

private:
	char* Buffer;
	char BeforeSkip, AfterSkip;
	int StartOfToken, EndOfToken;

	void SkipWhiteCharacters();
	void RemoveWhiteCharactersFromBegining(char** c);
	void RemoveWhiteCharactersFromEnd(char** c);
	Token* ParseAssigment(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseOr(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseAnd(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseEquality(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseNotEquality(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseGrater(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseGraterOrEqual(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseLess(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseLessrOrEqual(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseAddition(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseSubtraction(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseDivision(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseMuliplication(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseModulo(char* Left, char* Right, Dictionary* Memory, int* Limit);
	Token* ParseNot(char* Right, Dictionary* Memory, int* Limit);
	Token* ParseMinus(char* Right, Dictionary* Memory, int* Limit);
	Token* ParseToken(char* Expression, Dictionary* Memory, int* Limit, int Prioryty = 0);
	
	Code* ParseBlock(Dictionary* Memory, int* Limit);
	Code* ParseIf(Dictionary* Memory, int* Limit);
	Code* ParseWhile(Dictionary* Memory, int* Limit);
};