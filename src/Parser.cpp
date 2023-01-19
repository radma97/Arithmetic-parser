#include "Parser.h"

int Operation::Evaluate()
{
	// операция унаследована от Node
	if (op_ == '∗') {
		return (left_ -> Evaluate()) * (right_ -> Evaluate());
	}
	else if (op_ == '+') {
		return left_ -> Evaluate() + right_ -> Evaluate();
	}
	else if (op_ == '-') {
		return left_ -> Evaluate() - right_ -> Evaluate();
	}
	return 0;
	// если операция не распознана, но для корректной строки не дойдём
}