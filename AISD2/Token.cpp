#include <cstring>
#include <cstdlib>
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
Token::Token() : value(nullptr), IsConstant(false)
{
}

Token::Token(int * Variable) : value(Variable), IsConstant(false)
{
}

Token::Token(int Value) : IsConstant(true)
{
	value = new int(Value);
}

Token::~Token()
{
	if (value != nullptr && IsConstant)
	{
		delete value;
		value = nullptr;
	}
}

int* Token::Value()
{
	return value;
}

Token* ParseAssigment(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new AssignOperator(Left, Token::Parse(Right, Memory, Limit), Memory, Limit);
}

Token* ParseOr(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new OrOperator(Token::Parse(Left, Memory, Limit, 1), Token::Parse(Right, Memory, Limit, 1), Limit);
}

Token* ParseAnd(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new AndOperator(Token::Parse(Left, Memory, Limit, 2), Token::Parse(Right, Memory, Limit, 2), Limit);
}

Token* ParseEquality(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new EqualOperator(Token::Parse(Left, Memory, Limit, 3), Token::Parse(Right, Memory, Limit, 3), Limit);
}
Token* ParseNotEquality(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new NotEqualOperator(Token::Parse(Left, Memory, Limit, 3), Token::Parse(Right, Memory, Limit, 3), Limit);
}

Token* ParseGrater(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new GraterOperator(Token::Parse(Left, Memory, Limit, 4), Token::Parse(Right, Memory, Limit, 4), Limit);
}
Token* ParseGraterOrEqual(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right+=2;
	return new GraterOrEqualOperator(Token::Parse(Left, Memory, Limit, 4), Token::Parse(Right, Memory, Limit, 4), Limit);
}
Token* ParseLess(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new LessOperator(Token::Parse(Left, Memory, Limit, 4), Token::Parse(Right, Memory, Limit, 4), Limit);
}
Token* ParseLessrOrEqual(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new LessOrEqualOperator(Token::Parse(Left, Memory, Limit, 4), Token::Parse(Right, Memory, Limit, 4), Limit);
}

Token* ParseAddition(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new AdditionOperator(Token::Parse(Left, Memory, Limit, 5), Token::Parse(Right, Memory, Limit, 5), Limit);
}
Token* ParseSubtraction(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	char* tmp = strstr(Right + 1, "-");
	if (Left != Right || (Left == Right && tmp != NULL))
	{
		if (Left == Right)
			Right = tmp;
		Right[0] = '\0';
		Right++;
		return new SubtractionOperator(Token::Parse(Left, Memory, Limit, 5), Token::Parse(Right, Memory, Limit, 5), Limit);
	}
	else
		return Token::Parse(Left, Memory, Limit, 6);
}

Token* ParseDivision(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new DivisionOperator(Token::Parse(Left, Memory, Limit, 6), Token::Parse(Right, Memory, Limit, 6), Limit);
}
Token* ParseMuliplication(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new MultiplicationOperator(Token::Parse(Left, Memory, Limit, 6), Token::Parse(Right, Memory, Limit, 6), Limit);
}
Token* ParseModulo(char* Left, char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new ModuloOperator(Token::Parse(Left, Memory, Limit, 6), Token::Parse(Right, Memory, Limit, 6), Limit);
}

Token* ParseNot(char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	return new NotOperator(Token::Parse(Right, Memory, Limit, 7), Limit);
}
Token* ParseMinus(char* Right, Dictionary* Memory, int* Limit)
{
	Right[0] = '\0';
	Right++;
	if (Right[0] >= '0' && Right[0] <= '9')
		return new Token((-1) * atoi(Right));
	return new DecrementOperator(Token::Parse(Right, Memory, Limit, 7), Limit);
}

Token * Token::Parse(char * Expression, Dictionary* Memory, int* Limit, int Prioryty)
{
	char* Left = Expression, *Right;
	switch(Prioryty)
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
			if (Expression[0] >= '0' && Expression[0] <= '9')
				return new Token(atoi(Expression));
			else
				return new Token(Memory->Search(Expression));
	}
}