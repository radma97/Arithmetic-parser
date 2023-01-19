#pragma once
#include <memory>

struct Node // тип выводимых значений -- это базовый класс для переменных и цифр
{
public:
	virtual int Evaluate() {
		return 0;
	}
	// сделали метод виртуальным
}; // т. к. для каждого класса-потомка надо описывать, что делать в Evaluate

class Digit : public Node
{
public:
	// класс цифра, который будет всегда возвращать значение самой цифры
	Digit(int d) : d_(d) {
	}
	int Evaluate() override {
		return d_;
	}
private:
	const int d_;
};

class Variable : public Node // переменная x
{
public:
	Variable(const int& x) : x_(x) {
	}
	// сохраняем константную ссылку
	int Evaluate() override { // при вычислении x возвращаем его значение
		return x_;
	}
private:
	const int& x_;
}; // остались операции. Заметим, что у них разный приоритет. Умножение раньше всего

class Operation : public Node // для сохранения операции надо сохранять левый и правый операнды
{
	// унаследуем от Node
public:
	// передаём символ операции, левое и правое слагаемое
	Operation(char op, std::shared_ptr <Node> left, std::shared_ptr <Node> right) :
		op_(op), left_(left), right_(right) {
	}
	int Evaluate() override;

private:
	const char op_;
	std::shared_ptr <Node> left_, right_;
};
