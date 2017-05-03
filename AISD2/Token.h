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
protected:
	int* Limit;
private:
	bool IsConstant;
	int* value;
	
};