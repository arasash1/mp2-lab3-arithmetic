#pragma once
#ifndef __Arithmetic__
#define __Arithmetic__

#include <vector>
#include <stdexcept>
#include <string>
#include <map>

using namespace std;

struct Lexema
{
	int type; //1 операция(+, -, *, /), 2 число-операнд(число), 3 переменная(a, b, c...), 0 скобка
	string str;
};

class Arithmetic
{
private:
	string InputString;
	vector<Lexema> input;
	vector<Lexema> postfix;
	string PostfixString;
	map<string, double> variables;
	//map <string, int> priority;
	void Parser();
	void ToPostfix();
	double Calculate();
	bool Checker();
	static const int GetPriority(string& str);
	
	
public:
	Arithmetic(string& str);
	void Calculate_and_Postfix();
	string pubParse();
	double pubCalculate();

};
#endif
