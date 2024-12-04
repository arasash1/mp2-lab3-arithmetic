// реализация пользовательского приложения

#include <iostream>
#include "arithmetic.h"
#include "stack.h"

using namespace std;

int main()
{
	string str = "10*(a+b)*(a+b)-(40/12)";

	Arithmetic arithmetic(str);

	//std::cout << "done" << str << std::endl;
	//cout << arithmetic.pubCalculate();
	arithmetic.Calculate_and_Postfix();

  return 0;
}
