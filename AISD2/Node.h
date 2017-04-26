#pragma once

class Node
{
public:
	Node(const unsigned char& Id);
	~Node();
	const unsigned char Id;
	int* Variable;
	Node *Left, *Right, *Bottom;
};