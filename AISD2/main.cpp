
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
	auto Dict = new Dictionary(Root);
	char Data[1000];
	Dict->Insert("iiii", 1);
	/*Dict->Insert("abx", 4);
	Dict->Insert("ahm", 3);
	Dict->Insert("zxy", 2);
	Dict->Insert("a", 5);
	Dict->Insert("jakasDlugaNazwaZmiennej", 123456);
	auto a = Dict->Search("iiii");
	auto b = Dict->Search("abx");
	auto c = Dict->Search("ahm");
	auto d = Dict->Search("zxy");
	auto e = Dict->Search("a");
	auto f = Dict->Search("jakasDlugaNazwaZmiennej");
	printf("%d %d %d %d %d %d\n", *a, *b, *c, *d, *e, *f);
	delete Root;
	delete Dict;*/
	scanf("%s", Data);
	auto t = Token::Parse(Data, Dict);
	//auto i = t->Value();
	auto e = Dict->Search("test");
	printf("%d\n", *e);
	system("pause");
}