#pragma once
enum Operator
{
// 0 Prioryty
	ASSIGN,
// 1 Prioryty
	OR,
// 2 Prioryty
	AND,
// 3 Prioryty
	NOT_EQUALS,
	EQUALS,
// 4 Prioryty
	GRATER,
	SMALER,
	GRATER_OR_EQUAL,
	SMALLER_OR_EQUAL,
// 5 Prioryty
	PLUS,
	MINUS,
// 6 Prioryty
	DIVISION,
	MULITPLICATION,
	MODULO,
// 7 Priotyty
	NOT,
	DECREMENT,
	INCREMENT
};