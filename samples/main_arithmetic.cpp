// реализация пользовательского приложения

#include <iostream>
#include "arithmetic.h"
#include "stack.h"

using namespace std;

int main()
{
	string str = "10*(25/3030)-(a+b)";

	Arithmetic arithmetic(str);
	//cout << arithmetic.pubCalculate();
	arithmetic.Calculate_and_Postfix();

  return 0;
}
