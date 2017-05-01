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
	static Token* Parse(char* Expression, Dictionary* Memory, int Prioryty = 0);
protected:
	int* value;
private:
	bool IsConstant;
	
};