#include <string.h>
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

Token* ParseAssigment(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new AssignOperator(Left, Token::Parse(Right, Memory), Memory);
}

Token* ParseOr(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new OrOperator(Token::Parse(Left, Memory, 1), Token::Parse(Right, Memory, 1));
}

Token* ParseAnd(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new AndOperator(Token::Parse(Left, Memory, 2), Token::Parse(Right, Memory, 2));
}

Token* ParseEquality(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new EqualOperator(Token::Parse(Left, Memory, 3), Token::Parse(Right, Memory, 3));
}
Token* ParseNotEquality(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new NotEqualOperator(Token::Parse(Left, Memory, 3), Token::Parse(Right, Memory, 3));
}

Token* ParseGrater(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new GraterOperator(Token::Parse(Left, Memory, 4), Token::Parse(Right, Memory, 4));
}
Token* ParseGraterOrEqual(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right+=2;
	return new GraterOrEqualOperator(Token::Parse(Left, Memory, 4), Token::Parse(Right, Memory, 4));
}
Token* ParseLess(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new LessOperator(Token::Parse(Left, Memory, 4), Token::Parse(Right, Memory, 4));
}
Token* ParseLessrOrEqual(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right[1] = '\0';
	Right += 2;
	return new LessOrEqualOperator(Token::Parse(Left, Memory, 4), Token::Parse(Right, Memory, 4));
}

Token* ParseAddition(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new AdditionOperator(Token::Parse(Left, Memory, 5), Token::Parse(Right, Memory, 5));
}
Token* ParseSubtraction(char* Left, char* Right, Dictionary* Memory)
{
	char* tmp = strstr(Right + 1, "-");
	if (Left != Right || (Left == Right && tmp != NULL))
	{
		if (Left == Right)
			Right = tmp;
		Right[0] = '\0';
		Right++;
		return new SubtractionOperator(Token::Parse(Left, Memory, 5), Token::Parse(Right, Memory, 5));
	}
	else
		return Token::Parse(Left, Memory, 6);
}

Token* ParseDivision(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new DivisionOperator(Token::Parse(Left, Memory, 6), Token::Parse(Right, Memory, 6));
}
Token* ParseMuliplication(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new MultiplicationOperator(Token::Parse(Left, Memory, 6), Token::Parse(Right, Memory, 6));
}
Token* ParseModulo(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new ModuloOperator(Token::Parse(Left, Memory, 6), Token::Parse(Right, Memory, 6));
}

Token* ParseNot(char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new NotOperator(Token::Parse(Right, Memory, 7));
}
Token* ParseMinus(char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	if (Right[0] >= '0' && Right[0] <= '9')
		return new Token((-1) * atoi(Right));
	return new DecrementOperator(Token::Parse(Right, Memory, 7));
}

Token * Token::Parse(char * Expression, Dictionary* Memory, int Prioryty)
{
	char* Left = Expression, *Right;
	switch(Prioryty)
	{
		case 0:
			if ((Right = strstr(Expression, "=")) && Right != strstr(Expression, "==") 
				&& Right != strstr(Expression, "!=") + 1 && Right != strstr(Expression, ">=") + 1 
				&& Right != strstr(Expression, "<=") + 1)
				return ParseAssigment(Left, Right, Memory);
		case 1:
			if ((Right = strstr(Expression, "|")))
				return ParseOr(Left, Right, Memory);
		case 2:
			if (Right = strstr(Expression, "&"))
				return ParseAnd(Left, Right, Memory);
		case 3:
			if (Right = strstr(Expression, "!="))
				return ParseNotEquality(Left, Right, Memory);
			else if (Right = strstr(Expression, "=="))
				return ParseEquality(Left, Right, Memory);
		case 4:
			if (Right = strstr(Expression, "<"))
				return ParseLess(Left, Right, Memory);
			else if (Right = strstr(Expression, ">"))
				return ParseGrater(Left, Right, Memory);
			else if (Right = strstr(Expression, "<="))
				return ParseLessrOrEqual(Left, Right, Memory);
			else if (Right = strstr(Expression, ">="))
				return ParseGraterOrEqual(Left, Right, Memory);
		case 5:
			if (Right = strstr(Expression, "+"))
				return ParseAddition(Left, Right, Memory);
			else if (Right = strstr(Expression, "-"))
				return ParseSubtraction(Left, Right, Memory);
		case 6:
			if (Right = strstr(Expression, "*"))
				return ParseMuliplication(Left, Right, Memory);
			else if (Right = strstr(Expression, "/"))
				return ParseDivision(Left, Right, Memory);
			else if (Right = strstr(Expression, "%"))
				return ParseModulo(Left, Right, Memory);
		case 7:
			if (Right = strstr(Expression, "!"))
				return ParseNot(Right, Memory);
			else if (Right = strstr(Expression, "-"))
				return ParseMinus(Right, Memory);
		default:
			if (Expression[0] >= '0' && Expression[0] <= '9')
				return new Token(atoi(Expression));
			else
				return new Token(Memory->Search(Expression));
	}
}

