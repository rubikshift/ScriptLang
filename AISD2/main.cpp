#include <cstdlib>
#include <cstdio>
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
#include "Dictionary.h"

int main()
{
	auto Root = new Node('a');
	auto Memory = new Dictionary(Root);
	char Data[1001];
	Token* token;
	int* var;
	while (true)
	{
		scanf("%s", Data);
		var = Memory->Search(Data);
		if (var != nullptr)
			printf("%d\n", *var);
		else
			printf("%s\n", "Nul");
		token = Token::Parse(Data, Memory);
	}
		
	system("pause");
	delete token;
	delete Root;
	delete Memory;
}