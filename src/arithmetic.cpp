#include <arithmetic.h>
#include <stack.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Arithmetic::Checker() // запрещено: (++, --, **, //), (начинать с +, - , *, /), (отсутствие знака +, -, *, /)
{
	//25+30*(10+a)
	//+(.....)
	//)(....)
	if (input.empty())
	{
		throw "vector is null";
	}

	if (input[0].str == "+" || input[0].str == "*" || input[0].str == "/")
	{
		throw "str cant start with operation";
	}

	int num_of_scobs = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if ((i + 1) < input.size())
		{
			if ((input[i].type == 1) && (input[i + 1].type == 1))
			{
				throw "str cant have more than two operators in a row";
			}

			if ((input[i].type == 2) && (input[i + 1].type == 2))
			{
				throw "str cant have more than two digits in a row";
			}

			if ((input[i].type == 3) && (input[i + 1].type == 3))
			{
				throw "str cant have more than two alpha in a row";
			}
		}

		if (input[i].str == "(")
		{
			num_of_scobs++;
		}

		else if(input[i].str == ")")
		{
			num_of_scobs--;
		}

		if (num_of_scobs < 0)
		{
			throw "num of scobs are not equal";
		}
	}

	if (num_of_scobs != 0)
	{
		throw "num of scobs are not equal";
	}

	return true;
}

Arithmetic::Arithmetic(string& str): InputString(str)
{
}

void Arithmetic::Calculate_and_Postfix()
{
	this->Parser();
	this->Checker();
	this->ToPostfix();
	cout << "Postfix string: " << PostfixString;
	double calc = this->Calculate();
	cout << "Value of postfix: " << calc << endl;
}

//25.98+30,21*(10+a)
void Arithmetic::Parser()
{
	string digitstring;
	if (InputString.empty())
	{
		throw "string is null";
	}

	for (auto iter = InputString.begin(); iter != InputString.end(); ++iter)
	{
		if (isdigit(*iter))
		{
			Lexema digit;
			digitstring += *iter;

			auto next_iter = iter;
			++next_iter;
			while (next_iter != InputString.end() && (isdigit(*next_iter) || *next_iter == '.' || *next_iter == ','))
			{
				digitstring += *next_iter;
				++iter;
				++next_iter;
			}

			digit.type = 2;
			digit.str = digitstring;
			input.push_back(digit);
			digitstring.clear();
		}

		if ((*iter == '+') || (*iter == '-') || (*iter == '*') || (*iter == '/'))
		{
			Lexema operation;
			operation.type = 1;
			operation.str = string(1, *iter);
			input.push_back(operation);
		}

		if ((*iter == ')') || (*iter == '('))
		{
			Lexema skobka;
			skobka.type = 0;
			skobka.str = string(1, *iter);
			input.push_back(skobka);
		}

		if (isalpha(*iter))
		{
			Lexema symbol;
			symbol.type = 3;
			symbol.str = string(1, *iter);
			input.push_back(symbol);
		}

	}

	/*for (int i = 0; i < input.size(); i++)
	{
		cout << input[i].str << "|";
	}*/

}

void Arithmetic::ToPostfix()
{
	Stack<Lexema> stack;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i].type == 2 || input[i].type == 3)
		{
			postfix.push_back(input[i]);
		}

		if (input[i].str == "(")
		{
			stack.Push(input[i]);
		}

		if (input[i].str == ")")
		{
			while (!stack.IsEmpty() && stack.Top().str != "(")
			{
				Lexema top = stack.Top();
				postfix.push_back(top);
				stack.Pop();
			}

			if (!stack.IsEmpty())
			{
				stack.Pop();
			}
		}

		if (input[i].type == 1)
		{
			while (!stack.IsEmpty() && (GetPriority(input[i].str)) <= (GetPriority(stack.Top().str)))
			{
				Lexema top = stack.Top();
				postfix.push_back(top);
				stack.Pop();
			}

			stack.Push(input[i]);
		}
	}

	while (!stack.IsEmpty())
	{
		postfix.push_back(stack.Top());
		stack.Pop();
	}

	for (int i = 0; i < postfix.size(); i++)
	{
		PostfixString += postfix[i].str + " ";
	}
}

const int Arithmetic::GetPriority(string& str)
{
	static const map<string, int> priority = {
		{"+", 1},
		{"-", 1},
		{"*", 2},
		{"/", 2}
	};

	auto it = priority.find(str);
	return (it != priority.end()) ? it->second : -1;
}

double Arithmetic::Calculate()
{
	Stack<double> stack;

	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i].type == 2)
		{
			stack.Push(stod(postfix[i].str));
		}

		if (postfix[i].type == 3)
		{
			string input;

			cout << endl << "Input value of: " << postfix[i].str << " " << endl;
			cin >> input;

			double value = stod(input);

			stack.Push(value);
		}

		if (postfix[i].type == 1)
		{
			/*if (!stack.IsEmpty())
			{
				double right = stack.Top();
				stack.Pop();

				double left = stack.Top();
				stack.Pop();
			}*/

			double right = stack.Top();
			stack.Pop();

			double left = stack.Top();
			stack.Pop();

			double val;

			if (postfix[i].str == "+")
			{
				val = right + left;
				stack.Push(val);
			}

			if (postfix[i].str == "-")
			{
				val = (left - right);
				stack.Push(val);
			}
			if (postfix[i].str == "*")
			{
				val = (right * left);
				stack.Push(val);
			}
			if (postfix[i].str == "/")
			{
				val = (left/right);
				stack.Push(val);
			}

		}
		
	}

	double calculate = stack.Top();
	stack.Pop();

	return calculate;
}

string Arithmetic::pubParse()
{
	this->Parser();

	string str = "";
	for (int i = 0; i < input.size(); i++)
	{
		str += input[i].str + " ";
	}
	str.pop_back();

	return str;
}

double Arithmetic::pubCalculate()
{
	this->Parser();
	this->Checker();
	this->ToPostfix();

	return this->Calculate();
}