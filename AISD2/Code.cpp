#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "Token.h"
#include "Code.h"
#include "If.h"
#include "While.h"
#include "BlockOfCode.h"

Code::Code()
{
	LineOfCode = nullptr;
}

Code::Code(Token * LineOfCode)
{
	this->LineOfCode = LineOfCode;
}

Code::~Code()
{
	if(LineOfCode != nullptr)
		delete LineOfCode;
}

void Code::Execute()
{
	LineOfCode->Value();
}
