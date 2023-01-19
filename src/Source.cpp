#include <iostream>
#include <string>
#include "Parser.h"

using namespace std;

int main()
{
	int x = 0;
	string tokens = "5+7−x∗x+x";
	shared_ptr <Node> var1 = make_shared <Variable >(x);
	// делаем операцию умножения
	shared_ptr <Node> var2 = make_shared <Variable >(x);
	shared_ptr <Node> mul1 = make_shared <Operation >('∗', var1, var2);
	shared_ptr <Node> dig1 = make_shared <Digit >(5);
	// делаем операцию сложения
	shared_ptr <Node> dig2 = make_shared <Digit >(7);
	shared_ptr <Node> plus1 = make_shared <Operation >('+', dig1, dig2);
	shared_ptr <Node> var3 = make_shared <Variable >(x);
	shared_ptr <Node> minus1 = make_shared <Operation >('−', plus1, mul1);
	shared_ptr <Node> plus2 =
		make_shared <Operation >('+', minus1, var3);
	// итоговый результат будет в самом правом и самом неприоритетном операторе, plus2
	cout << "Enter x: ";
	while (cin >> x) {
		// пока пользователь будет вводить значения, вычисляем
		cout << plus2 -> Evaluate() << endl;
		cout << "Enter x: ";
	}
	return 0;
}
