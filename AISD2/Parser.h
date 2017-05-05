#pragma once
#include "Token.h"
#include "Code.h"
#include "Stack.h"
#include "Operators.h"
class Parser
{
public:
	Parser();
	~Parser();
	Code* ParseCode(Dictionary* Memory, int* Limit);

private:
	Stack<Token*>* RPNStack;
	Stack<Operators>* OperatorsStack;
	char* Buffer;
	char BeforeSkip, AfterSkip;
	int StartOfToken, EndOfToken;

	void SkipWhiteCharacters();
	void RemoveWhiteCharactersFromBegining(char** c);
	void RemoveWhiteCharactersFromEnd(char** c);
	int OperatorPrioryty(Operators O);
	Token* ParseExpression(char* Expression, Dictionary* Memory, int* Limit, int Prioryty = 0);
	Token* ParseToken(char* T, Dictionary* Memory);
	void ParseOperator(Operators O, int* Limit);
	void GenerateTokenOnStack(Operators O, int* Limit);

	Code* ParseSingleExpression(Dictionary* Memory, int* Limit);
	Code* ParseInstruction(Dictionary* Memory, int* Limit);
	Code* ParseIf(Dictionary* Memory, int* Limit);
	Code* ParseWhile(Dictionary* Memory, int* Limit);
};