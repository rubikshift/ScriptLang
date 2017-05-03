#pragma once
#include "Dictionary.h"
class Token
{
public:
	virtual int* Value() = 0;
protected:
	int* Limit;
	
};