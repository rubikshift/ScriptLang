#include "Node.h"
Node::Node(const unsigned char& Id) : Left(nullptr), Right(nullptr), Bottom(nullptr), Id(Id), Variable(nullptr)
{
}

Node::~Node()
{
	if (Variable != nullptr)
		delete Variable;
	if (Left != nullptr)
		delete Left;
	if (Right != nullptr)
		delete Right;
	if (Bottom != nullptr)
		delete Bottom;
}
