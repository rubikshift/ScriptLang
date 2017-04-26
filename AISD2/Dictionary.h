#pragma once
#include "Node.h"
class Dictionary
{
public:
	Dictionary(Node* Root);
	~Dictionary();
	void Insert(const char* Name, const int& Value);
	int* Search(const char* Name);
private:
	Node* Root;
	Node* Current;
	Node* BstInsert(const char Id);
	Node* BstSearch(const char Id);
};