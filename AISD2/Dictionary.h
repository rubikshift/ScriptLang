#pragma once
#include "Node.h"
class Dictionary
{
public:
	Dictionary(Node* Root);
	void Insert(const char* Name, const int& Value);
	Variable* Search(const char* Name);
private:
	Node* Root;
	Node* Current;
	Node* BstInsert(const char Id);
	Node* BstSearch(const char Id);
};