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
#include "MinusOperator.h"
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
#include "Constant.h"
#include "Variable.h"
#include "Code.h"
#include "If.h"
#include "While.h"
#include "BlockOfCode.h"
#include "Stack"

#define BUFFER_SIZE 75000

Parser::Parser() : BeforeSkip(0), AfterSkip(0), StartOfToken(0), EndOfToken(0)
{
	Buffer = new char[BUFFER_SIZE];
	RPNStack = new Stack<Token*>();
	OperatorsStack = new Stack<Operators>();
	std::cin.get(Buffer, BUFFER_SIZE, NULL);
}

Parser::~Parser()
{
	delete[] Buffer;
	delete RPNStack;
	delete OperatorsStack;
}

void Parser::SkipWhiteCharacters()
{
	while (isspace(Buffer[EndOfToken]))
		EndOfToken++;
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

int Parser::OperatorPrioryty(Operators O)
{
	switch (O)
	{
	case ASSIGN: return 0;
	case OR: return 1;
	case AND: return 2;
	case NOT_EQUAL:
	case EQUAL: return 3;
	case GRATER:
	case LESS:
	case GRATER_OR_EQUAL:
	case LESS_OR_EQUAL: return 4;
	case ADDITION: return 5;
	case SUBTRACTION: return 6;
	case MULTIPLICATION:
	case DIVISION:
	case MODULO: return 7;
	case NOT:
	case MINUS: return 8;
	default: return -1;
	}
}

Token* Parser::ParseToken(char* T, Dictionary* Memory)
{
	RemoveWhiteCharactersFromBegining(&T);
	RemoveWhiteCharactersFromEnd(&T);
	if (T[0] == 0)
		return nullptr;
	if (isdigit(T[0]))
		return new Constant(atoi(T));
	else if (T[0] == '-')
	{
		T[0] = 0;
		T++;
		return new Constant((-1)* atoi(T));
	}
	else
		return new Variable(T, Memory);
}

void Parser::GenerateTokenOnStack(Operators O, int* Limit)
{
	Token* Right = RPNStack->Pop();
	Token* Left;
	if (O == NOT)
		RPNStack->Push(new NotOperator(Right, Limit));
	else if (O == MINUS)
		RPNStack->Push(new MinusOperator(Right, Limit));
	else
	{
		Left = RPNStack->Pop();
		if (O == ASSIGN)
			RPNStack->Push(new AssignOperator(Left, Right, Limit));
		else if (O == OR)
			RPNStack->Push(new OrOperator(Left, Right, Limit));
		else if (O == AND)
			RPNStack->Push(new AndOperator(Left, Right, Limit));
		else if (O == NOT_EQUAL)
			RPNStack->Push(new NotEqualOperator(Left, Right, Limit));
		else if (O == EQUAL)
			RPNStack->Push(new EqualOperator(Left, Right, Limit));
		else if (O == LESS_OR_EQUAL)
			RPNStack->Push(new LessOrEqualOperator(Left, Right, Limit));
		else if (O == LESS)
			RPNStack->Push(new LessOperator(Left, Right, Limit));
		else if (O == GRATER_OR_EQUAL)
			RPNStack->Push(new GraterOrEqualOperator(Left, Right, Limit));
		else if (O == GRATER)
			RPNStack->Push(new GraterOperator(Left, Right, Limit));
		else if (O == ADDITION)
			RPNStack->Push(new AdditionOperator(Left, Right, Limit));
		else if (O == SUBTRACTION)
			RPNStack->Push(new SubtractionOperator(Left, Right, Limit));
		else if (O == DIVISION)
			RPNStack->Push(new DivisionOperator(Left, Right, Limit));
		else if (O == MULTIPLICATION)
			RPNStack->Push(new MultiplicationOperator(Left, Right, Limit));
		else if (O == MODULO)
			RPNStack->Push(new ModuloOperator(Left, Right, Limit));
	}
}

void Parser::ParseOperator(Operators O, int* Limit)
{
	if (O == OPENING_BRACKET)
		OperatorsStack->Push(O);
	else if (O == CLOSING_BRACKET)
	{
		while (OperatorsStack->LookAtLast() != OPENING_BRACKET)
			GenerateTokenOnStack(OperatorsStack->Pop(), Limit);
		OperatorsStack->Pop();
	}
	else if (OperatorsStack->IsEmpty() || OperatorsStack->LookAtLast() == OPENING_BRACKET || OperatorPrioryty(OperatorsStack->LookAtLast()) <= OperatorPrioryty(O))
		OperatorsStack->Push(O);
	else if (OperatorPrioryty(OperatorsStack->LookAtLast()) > OperatorPrioryty(O))
	{
		while (!OperatorsStack->IsEmpty() && (OperatorPrioryty(OperatorsStack->LookAtLast()) >= OperatorPrioryty(O) && OperatorsStack->LookAtLast() != OPENING_BRACKET))
			GenerateTokenOnStack(OperatorsStack->Pop(), Limit);
		OperatorsStack->Push(O);
	}
}

Token * Parser::ParseExpression(char * Expression, Dictionary* Memory, int* Limit, int Prioryty)
{
	int i = 0, q = 0;
	Token* T;
	while (Expression[i] != '\0' && Expression[i] != '}')
	{
		while (isalpha(Expression[i]) || isdigit(Expression[i])) i++;
		while (isspace(Expression[i])) i++;
		if (Expression[i] == '(')
		{
			Expression[i] = '\0';
			ParseOperator(OPENING_BRACKET, Limit);
			q = ++i;
		}
		else if (Expression[i] == ')')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(CLOSING_BRACKET, Limit);
			q = ++i;
		}
		else if (Expression[i] == '=' && (Expression[i + 1] != '='
			&& Expression[i - 1] != '!' && Expression[i - 1] != '>'
			&& Expression[i - 1] != '<'))
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(ASSIGN, Limit);
			q = ++i;
		}
		else if (Expression[i] == '|')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(OR, Limit);
			q = ++i;
		}
		else if (Expression[i] == '&')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(AND, Limit);
			q = ++i;
		}
		else if (Expression[i] == '!' && Expression[i + 1] == '=')
		{
			Expression[i] = '\0';
			Expression[i + 1] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(NOT_EQUAL, Limit);
			i += 2;
			q = i;
		}
		else if (Expression[i] == '=' && Expression[i + 1] == '=')
		{
			Expression[i] = '\0';
			Expression[i + 1] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(EQUAL, Limit);
			i += 2;
			q = i;
		}
		else if (Expression[i] == '>' && Expression[i + 1] == '=')
		{
			Expression[i] = '\0';
			Expression[i + 1] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(GRATER_OR_EQUAL, Limit);
			i += 2;
			q = i;
		}
		else if (Expression[i] == '<' && Expression[i + 1] == '=')
		{
			Expression[i] = '\0';
			Expression[i + 1] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(LESS_OR_EQUAL, Limit);
			i += 2;
			q = i;
		}
		else if (Expression[i] == '>')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(GRATER, Limit);
			q = ++i;
		}
		else if (Expression[i] == '<')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(LESS, Limit);
			q = ++i;
		}
		else if (Expression[i] == '+')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(ADDITION, Limit);
			q = ++i;
		}
		else if (Expression[i] == '-')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (q == i && isalpha(Expression[i + 1]) || Expression[i + 1] == '(')
			{
				ParseOperator(MINUS, Limit);
				q = ++i;
			}
			else if ((T == nullptr && Expression[i + 1] == '-') || (q != i && T != nullptr))
			{
				Expression[i] = '\0';
				if (T != nullptr) RPNStack->Push(T);
				ParseOperator(SUBTRACTION, Limit);
				q = ++i;
			}
			else
			{
				Expression[i] = '-';
				++i;
			}
		}
		else if (Expression[i] == '/')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(DIVISION, Limit);
			q = ++i;
		}
		else if (Expression[i] == '*')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(MULTIPLICATION, Limit);
			q = ++i;
		}
		else if (Expression[i] == '%')
		{
			Expression[i] = '\0';
			T = ParseToken(Expression + q, Memory);
			if (T != nullptr) RPNStack->Push(T);
			ParseOperator(MODULO, Limit);
			q = ++i;
		}
		else if (Expression[i] == '!')
		{
			Expression[i] = '\0';
			ParseOperator(NOT, Limit);
			q = ++i;
		}
	}
	if (Expression[i] == '}')
	{
		Expression[i] = '\0';
		T = ParseToken(Expression + q, Memory);
		if (T != nullptr) RPNStack->Push(T);
		Expression[i] = '}';
	}
	else
	{
		T = ParseToken(Expression + q, Memory);
		if (T != nullptr) RPNStack->Push(T);
	}
	while (!OperatorsStack->IsEmpty())
		GenerateTokenOnStack(OperatorsStack->Pop(), Limit);

	return RPNStack->Pop();
}

Code* Parser::ParseWhile(Dictionary* Memory, int* Limit)
{
	while (Buffer[EndOfToken] != '(')
		EndOfToken++;
	StartOfToken = ++EndOfToken;
	while (Buffer[EndOfToken] != '{')
		EndOfToken++;
	while (Buffer[EndOfToken] != ')')
		EndOfToken--;
	Buffer[EndOfToken] = 0;
	while (Buffer[EndOfToken] != '{')
		EndOfToken++;
	EndOfToken++;
	Token* t = ParseExpression(Buffer + StartOfToken, Memory, Limit);
	return new While(t, ParseCode(Memory, Limit), Limit);
}
Code* Parser::ParseIf(Dictionary* Memory, int* Limit)
{
	while (Buffer[EndOfToken] != '(')
		EndOfToken++;
	StartOfToken = ++EndOfToken;
	while (Buffer[EndOfToken] != '{')
		EndOfToken++;
	while (Buffer[EndOfToken] != ')')
		EndOfToken--;
	Buffer[EndOfToken] = 0;
	while (Buffer[EndOfToken] != '{')
		EndOfToken++;
	EndOfToken++;
	Token* t = ParseExpression(Buffer + StartOfToken, Memory, Limit);
	return new If(t, ParseCode(Memory, Limit), Limit);
}
Code* Parser::ParseSingleExpression(Dictionary* Memory, int* Limit)
{
	StartOfToken = EndOfToken;
	while (Buffer[EndOfToken] != '}' && Buffer[EndOfToken] != 0)
	{
		BeforeSkip = Buffer[EndOfToken];
		EndOfToken++;
		if (isspace(Buffer[EndOfToken]))
		{
			SkipWhiteCharacters();
			AfterSkip = Buffer[EndOfToken];
		}
		else
			AfterSkip = 0;

		if ((isdigit(BeforeSkip) || isalpha(BeforeSkip) || BeforeSkip == ')') &&
			(isdigit(AfterSkip) || isalpha(AfterSkip) || AfterSkip == '?' || AfterSkip == '@' || AfterSkip == '('))
		{
			Buffer[EndOfToken - 1] = 0;
			break;
		}
	}
	if (strlen(Buffer + StartOfToken) == 1 && Buffer[EndOfToken] == '}')
		return nullptr;
	return new Code(ParseExpression(Buffer + StartOfToken, Memory, Limit));
}

Code* Parser::ParseInstruction(Dictionary* Memory, int* Limit)
{
	if (Buffer[EndOfToken] == '?')
		return ParseIf(Memory, Limit);
	else if (Buffer[EndOfToken] == '@')
		return ParseWhile(Memory, Limit);
	else
		return ParseSingleExpression(Memory, Limit);
}

Code * Parser::ParseCode(Dictionary* Memory, int* Limit)
{
	Code *p, *q;
	SkipWhiteCharacters();
	p = ParseInstruction(Memory, Limit);
	while (Buffer[EndOfToken] != '}' && Buffer[EndOfToken] != 0)
	{
		SkipWhiteCharacters();
		q = ParseInstruction(Memory, Limit);
		p = new BlockOfCode(p, q);
		SkipWhiteCharacters();
	}
	EndOfToken++;
	return p;
}