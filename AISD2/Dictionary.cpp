#include "Dictionary.h"
#include <cstring>
Dictionary::Dictionary(Node * Root) : Root(Root), Current(Root)
{
}

Dictionary::~Dictionary()
{
}

int* Dictionary::Insert(const char * Name, const int* Value)
{
	Current = Root;
	size_t NameSize = strlen(Name);
	for (int i = 0; i < NameSize - 1; i++)
	{
		Current = BstInsert(Name[i]);
		if (Current->Bottom == nullptr)
			Current->Bottom = new Node(Name[i + 1]);
		Current = Current->Bottom;
	}
	if (Current->Id != Name[NameSize - 1])
		Current = BstInsert(Name[NameSize - 1]);
	if (Current->Variable == nullptr && Value != nullptr)
		Current->Variable = new int(*Value);
	else if(Value != nullptr)
		*Current->Variable = *Value;
	return Current->Variable;
}

int* Dictionary::Search(const char * Name)
{
	Current = Root;
	size_t NameSize = strlen(Name);
	for (int i = 0; i < NameSize - 1; i++)
	{
		Current = BstSearch(Name[i]);
		if (Current == nullptr)
			return nullptr;
		Current = Current->Bottom;
	}
	if (Current != nullptr && Current->Id != Name[NameSize - 1])
		Current = BstSearch(Name[NameSize - 1]);
	if (Current == nullptr)
		return nullptr;
	return Current->Variable;
}

Node * Dictionary::BstInsert(const char Id)
{
	if (Current->Id == Id)
		return Current;
	else if (Current->Id > Id)
	{
		if (Current->Left != nullptr)
		{
			Current = Current->Left;
			return BstInsert(Id);
		}
		else
		{
			Current->Left = new Node(Id);
			return Current->Left;
		}
	}
	else
	{
		if (Current->Right != nullptr)
		{
			Current = Current->Right;
			return BstInsert(Id);
		}
		else
		{
			Current->Right = new Node(Id);
			return Current->Right;
		}
	}
}

Node * Dictionary::BstSearch(const char Id)
{
	if (Current == nullptr)
		return nullptr;
	else if (Current->Id == Id)
		return Current;
	else if (Current->Id > Id)
	{
		Current = Current->Left;
		return BstSearch(Id);
	}
	else
	{
		Current = Current->Right;
		return BstSearch(Id);
	}
}
