#pragma once
#include "Dictionary.h"
class Token
{
public:
	Token();
	Token(int* Variable);
	Token(int Value);
	virtual ~Token();
	virtual int* Value();
	static Token* Parse(char* Expression, Dictionary* Memory);
	bool IsConstant;
protected:
	int* value;
	
};