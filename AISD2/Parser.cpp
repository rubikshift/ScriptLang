#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include "Token.h"
#include "Operator.h"
#include "BinaryOperator.h"
#include "AdditionOperator.h"
#include "AndOperator.h"
#include "AssignOperator.h"
#include "DecrementOperator.h"
#include "DivisionOperator.h"
#include "EqualOperator.h"
#include "GraterOperator.h"
#include "GraterOrEqualOperator.h"
#include "LessOperator.h"
#include "LessOrEqualOperator.h"
#include "ModuloOperator.h"
#include "MultiplicationOperator.h"
#include "NotEqualOperator.h"
#include "NotOperator.h"
#include "OrOperator.h"
#include "SubtractionOperator.h"
#include "Parser.h"
#include "Token.h"
#include "Code.h"
#include "If.h"
#include "While.h"
#include "BlockOfCode.h"

Parser::Parser() : BeforeSkip(0), AfterSkip(0), StartOfToken(0), EndOfToken(0)
{
	Buffer = new char[2000];
	std::cin.getline(Buffer, 2000, NULL);
}

Parser::~Parser()
{
	delete[] Buffer;
}

void Parser::SkipWhiteCharacters()
{
	bool Skipped = false;
	while (isspace(Buffer[EndOfToken]) && (Skipped = true))
		EndOfToken++;
	AfterSkip = Buffer[EndOfToken];
	if (Skipped == false)
		AfterSkip = 0;
}

void Parser::RemoveWhiteCharactersFromBegining(char** c)
{
	while (isspace(**c))
		(*c)++;
}

void Parser::RemoveWhiteCharactersFromEnd(char ** c)
{
	for (int i = strlen(*c) - 1; i > 0; i--)
		if (isspace((*c)[i]))
			(*c)[i] = 0;
}

Token* Parser::ParseAssigment(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	RemoveWhiteCharactersFromBegining(&Left);
	RemoveWhiteCharactersFromEnd(&Left);
	return new AssignOperator(Left, ParseToken(Right, Memory, Limit), Memory, Limit);
}

Token* Parser::ParseOr(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new OrOperator(ParseToken(Left, Memory, Limit, 1),
		ParseToken(Right, Memory, Limit, 1), Limit);
}

Token* Parser::ParseAnd(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new AndOperator(ParseToken(Left, Memory, Limit, 2),
		ParseToken(Right, Memory, Limit, 2), Limit);
}

Token* Parser::ParseEquality(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new EqualOperator(ParseToken(Left, Memory, Limit, 3),
		ParseToken(Right, Memory, Limit, 3), Limit);
}
Token* Parser::ParseNotEquality(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new NotEqualOperator(ParseToken(Left, Memory, Limit, 3),
		ParseToken(Right, Memory, Limit, 3), Limit);
}

Token* Parser::ParseGrater(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new GraterOperator(ParseToken(Left, Memory, Limit, 4),
		ParseToken(Right, Memory, Limit, 4), Limit);
}
Token* Parser::ParseGraterOrEqual(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new GraterOrEqualOperator(ParseToken(Left, Memory, Limit, 4),
		ParseToken(Right, Memory, Limit, 4), Limit);
}
Token* Parser::ParseLess(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new LessOperator(ParseToken(Left, Memory, Limit, 4),
		ParseToken(Right, Memory, Limit, 4), Limit);
}
Token* Parser::ParseLessrOrEqual(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new LessOrEqualOperator(ParseToken(Left, Memory, Limit, 4),
		ParseToken(Right, Memory, Limit, 4), Limit);
}

Token* Parser::ParseAddition(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new AdditionOperator(ParseToken(Left, Memory, Limit, 5),
		ParseToken(Right, Memory, Limit, 5), Limit);
}
Token* Parser::ParseSubtraction(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	char* tmp = strstr(Right + 1, "-");
	if (Left != Right || (Left == Right && tmp != NULL))
	{
		if (Left == Right)
			Right = tmp;
		Right[0] = '\0';
		Right++;
		return new SubtractionOperator(ParseToken(Left, Memory, Limit, 5),
			ParseToken(Right, Memory, Limit, 5), Limit);
	}
	else
		return ParseToken(Left, Memory, Limit, 6);
}

Token* Parser::ParseDivision(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new DivisionOperator(ParseToken(Left, Memory, Limit, 6),
		ParseToken(Right, Memory, Limit, 6), Limit);
}
Token* Parser::ParseMuliplication(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new MultiplicationOperator(ParseToken(Left, Memory, Limit, 6),
		ParseToken(Right, Memory, Limit, 6), Limit);
}
Token* Parser::ParseModulo(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new ModuloOperator(ParseToken(Left, Memory, Limit, 6),
		ParseToken(Right, Memory, Limit, 6), Limit);
}

Token* Parser::ParseNot(char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new NotOperator(ParseToken(Right, Memory, Limit, 7), Limit);
}
Token* Parser::ParseMinus(char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	if (isdigit(Right[0]))
		return new Token((-1) * atoi(Right));
	return new DecrementOperator(ParseToken(Right, Memory, Limit, 7), Limit);
}

Token * Parser::ParseToken(char * Expression, Dictionary* Memory, int* Limit, int Prioryty)
{
	char* Left = Expression, *Right;
	switch (Prioryty)
	{
	case 0:
		if ((Right = strstr(Expression, "=")) && Right != strstr(Expression, "==")
			&& Right != strstr(Expression, "!=") + 1 && Right != strstr(Expression, ">=") + 1
			&& Right != strstr(Expression, "<=") + 1)
			return ParseAssigment(Left, Right, Memory, Limit);
	case 1:
		if ((Right = strstr(Expression, "|")))
			return ParseOr(Left, Right, Memory, Limit);
	case 2:
		if (Right = strstr(Expression, "&"))
			return ParseAnd(Left, Right, Memory, Limit);
	case 3:
		if (Right = strstr(Expression, "!="))
			return ParseNotEquality(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, "=="))
			return ParseEquality(Left, Right, Memory, Limit);
	case 4:
		if (Right = strstr(Expression, "<"))
			return ParseLess(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, ">"))
			return ParseGrater(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, "<="))
			return ParseLessrOrEqual(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, ">="))
			return ParseGraterOrEqual(Left, Right, Memory, Limit);
	case 5:
		if (Right = strstr(Expression, "+"))
			return ParseAddition(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, "-"))
			return ParseSubtraction(Left, Right, Memory, Limit);
	case 6:
		if (Right = strstr(Expression, "*"))
			return ParseMuliplication(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, "/"))
			return ParseDivision(Left, Right, Memory, Limit);
		else if (Right = strstr(Expression, "%"))
			return ParseModulo(Left, Right, Memory, Limit);
	case 7:
		if (Right = strstr(Expression, "!"))
			return ParseNot(Right, Memory, Limit);
		else if (Right = strstr(Expression, "-"))
			return ParseMinus(Right, Memory, Limit);
	default:
		RemoveWhiteCharactersFromBegining(&Expression);
		RemoveWhiteCharactersFromEnd(&Expression);
		if (isdigit(Expression[0]))
			return new Token(atoi(Expression));
		else
			return new Token(Memory->Search(Expression));
	}
}

Code* Parser::ParseWhile(Dictionary* Memory, int* Limit)
{
	return nullptr;
}
Code* Parser::ParseIf(Dictionary* Memory, int* Limit)
{
	return nullptr;
}

Code * Parser::ParseCode(Dictionary* Memory, int* Limit)
{
	StartOfToken = EndOfToken;
	Code* c;
	while (Buffer[EndOfToken] != 0)
	{
		SkipWhiteCharacters();
		if ((isdigit(BeforeSkip) || isalpha(BeforeSkip)) && (isdigit(AfterSkip) || isalpha(AfterSkip))) 
		{
			Buffer[EndOfToken - 1] = 0;
			c = new Code(ParseToken(Buffer + StartOfToken, Memory, Limit));
			return new BlockOfCode(c, ParseCode(Memory, Limit));
		}
		if (isspace(Buffer[EndOfToken]) == 0)
		{
			BeforeSkip = Buffer[EndOfToken];
			EndOfToken++;
		}
	}
	c = new Code(ParseToken(Buffer + StartOfToken, Memory, Limit));
	return c;
}