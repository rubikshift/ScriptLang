#include "Dictionary.h"
#include <cstdlib>
#include <cstdio>
int main()
{
	auto root = new Node('i');
	auto Dict = new Dictionary(root);
	Dict->Insert("iiii", 1);
	Dict->Insert("abx", 4);
	Dict->Insert("ahm", 3);
	Dict->Insert("zxy", 2);
	Dict->Insert("a", 5);
	Dict->Insert("jakasDlugaNazwaZmiennej", 123456);
	auto a = Dict->Search("iiii");
	auto b = Dict->Search("abx");
	auto c = Dict->Search("ahm");
	auto d = Dict->Search("zxy");
	auto e = Dict->Search("a");
	auto f = Dict->Search("jakasDlugaNazwaZmiennej");
	printf("%d %d %d %d %d %d\n", a->GetValue(), b->GetValue(), c->GetValue(), d->GetValue(), e->GetValue(), f->GetValue());
	system("pause");
}