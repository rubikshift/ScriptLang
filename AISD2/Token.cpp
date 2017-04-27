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

Token* ParseAddition(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new AdditionOperator(Token::Parse(Left, Memory), Token::Parse(Right, Memory));
}

Token* ParseAssigment(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new AssignOperator(Left, Token::Parse(Right, Memory), Memory);
}

Token* ParseSubtraction(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new SubtractionOperator(Token::Parse(Left, Memory), Token::Parse(Right, Memory));
}

Token* ParseDivision(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new DivisionOperator(Token::Parse(Left, Memory), Token::Parse(Right, Memory));
}

Token* ParseMuliplication(char* Left, char* Right, Dictionary* Memory)
{
	Right[0] = '\0';
	Right++;
	return new MultiplicationOperator(Token::Parse(Left, Memory), Token::Parse(Right, Memory));
}

Token * Token::Parse(char * Expression, Dictionary* Memory)
{
	char* Left = Expression, *Right;
	if (Right = strstr(Expression, "="))
		return ParseAssigment(Left, Right, Memory);
	else if (Right = strstr(Expression, "|"));
	else if (Right = strstr(Expression, "&"));
	else if (Right = strstr(Expression, "!="));
	else if (Right = strstr(Expression, "=="));
	else if (Right = strstr(Expression, "<"));
	else if (Right = strstr(Expression, ">"));
	else if (Right = strstr(Expression, "<="));
	else if (Right = strstr(Expression, ">="));
	else if (Right = strstr(Expression, "+"))
		return ParseAddition(Left, Right, Memory);
	else if (Right = strstr(Expression, "-"))
		return ParseSubtraction(Left, Right, Memory);
	else if (Right = strstr(Expression, "/"))
		return ParseDivision(Left, Right, Memory);
	else if (Right = strstr(Expression, "*"))
		return ParseMuliplication(Left, Right, Memory);
	else if (Right = strstr(Expression, "%"));
	else if (Right = strstr(Expression, "!"));
	else if (Expression[0] >= '0' && Expression[0] <= '9')
		return new Token(atoi(Expression));
	else
		return new Token(Memory->Search(Expression));
}

