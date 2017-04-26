#pragma once
class Variable
{
public:
	Variable();
	Variable(const int& Value);
	bool IsNul() const;
	int GetValue() const;
	void operator=(const int& Value);
private:
	int Value;
	bool Nul;
};