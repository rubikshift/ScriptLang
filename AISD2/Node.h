#pragma once
#include "Variable.h"
class Node
{
public:
	Node(const unsigned char& Id);
	const unsigned char Id;
	Variable Var;
	Node *Left, *Right, *Bottom;
};