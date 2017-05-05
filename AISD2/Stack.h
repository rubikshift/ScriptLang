#pragma once

template <typename T> class StackNode
{
public:
	StackNode() : Prev(nullptr) {};
	T Data;
	StackNode<T>* Prev;
};

template <typename T> class Stack
{
public:
	Stack() : Last(nullptr) {};
	~Stack()
	{
		if (Last != nullptr)
			delete Last;
		Last = nullptr;
	}
	void Push(T Data)
	{
		StackNode<T>* N = new StackNode<T>();
		N->Data = Data;
		N->Prev = Last;
		Last = N;
	}
	bool IsEmpty()
	{
		return Last == nullptr;
	}
	T LookAtLast()
	{
		return Last->Data;
	}
	T Pop()
	{
		T R = Last->Data;
		StackNode<T>* N = Last;
		Last = N->Prev;
		delete N;
		return R;
	}
private:
	StackNode<T>* Last;
};
