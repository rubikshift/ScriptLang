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
}

int* Token::Value()
{
	return value;
}

Token * Token::Parse(char * Expression, Dictionary* Memory)
{
	char* Left = Expression, *Right;
	if (Right = strstr(Expression, "="))
	{
		Right[0] = '\0';
		Right++;
		Memory->Insert(Left, atoi(Right));
	}
	else if (Right = strstr(Expression, "|"));
	else if (Right = strstr(Expression, "&"));
	else if (Right = strstr(Expression, "!="));
	else if (Right = strstr(Expression, "=="));
	else if (Right = strstr(Expression, "<"));
	else if (Right = strstr(Expression, ">"));
	else if (Right = strstr(Expression, "<="));
	else if (Right = strstr(Expression, ">="));
	else if (Right = strstr(Expression, "+"))
	{
		Right[0] = '\0';
		Right++;
		return new AdditionOperator(Parse(Left, Memory), Parse(Right, Memory));
	}
	else if (Right = strstr(Expression, "-"));
	else if (Right = strstr(Expression, "/"));
	else if (Right = strstr(Expression, "*"));
	else if (Right = strstr(Expression, "%"));
	else if (Right = strstr(Expression, "!"));
	else if (Expression[0] >= '0' && Expression[0] <= '9')
		return new Token(atoi(Expression));
	else
		return new Token(Memory->Search(Expression));
}

