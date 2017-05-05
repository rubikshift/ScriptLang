#include <cstdlib>
#include <iostream>
#include <cstring>
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
#include "Dictionary.h"
#include "Parser.h"
#include "Code.h"
int main()
{
	auto Root = new Node('a');
	auto Memory = new Dictionary(Root);
	char *tmp, *Variables = new char[1000];
	int Limit = 0, LimitAtStart = 0, *Value;
	
	std::cin.getline(Variables, 1000);
	sscanf(Variables, "%d", &Limit);
	LimitAtStart = Limit;
	std::cin.getline(Variables, 1000);

	Parser* P = new Parser();
	Code* Program;
	Program = P->ParseCode(Memory, &Limit);
	Program->Execute();
	printf("%d\n", LimitAtStart-Limit);
	while (Variables != NULL)
	{
		tmp = Variables;
		Variables = strstr(Variables, " ");
		if (Variables != NULL)
		{
			Variables[0] = 0;
			Variables++;
		}
		Value = Memory->Search(tmp);
		if (Value != nullptr)
			printf("%s %d\n", tmp, *Value);
		else
			printf("%s %s\n", tmp, "Nul");
	}
	delete P;
	delete Program;
	delete Variables;
	delete Root;
	delete Memory;
}