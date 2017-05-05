#pragma once
#include "Dictionary.h"
class Token
{
public:
	virtual int* Value() = 0;
	virtual int* Insert(int* value) { return nullptr; };
protected:
	int* Limit;
	
};