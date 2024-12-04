// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"


TEST(Arithmetic, can_create)
{
	string str = "(43+223)*(a+b)+10";
	ASSERT_NO_THROW(Arithmetic ar(str));
}

TEST(Arithmetic, cant_start_with_operation)
{
	string str = "+(43+223)*(a+b)+10";
	Arithmetic ar(str);

	ASSERT_ANY_THROW(ar.Calculate_and_Postfix());
}

TEST(Arithmetic, cant_with_more_than_two_operation)
{
	string str = "(43+223)***(a+b)+10";
	Arithmetic ar(str);

	ASSERT_ANY_THROW(ar.Calculate_and_Postfix());
}

TEST(Arithmetic, cant_be_more_close_skobs)
{
	string str = "(43+223))))*(((a+b)+10";
	Arithmetic ar(str);

	ASSERT_ANY_THROW(ar.Calculate_and_Postfix());
}

TEST(Arithmetic, can_parse_correctly)
{
	string str = "(43+223)*(a+b)+10";

	Arithmetic ar(str);
	string res = ar.pubParse();
	string str1 = "( 43 + 223 ) * ( a + b ) + 10";


	EXPECT_EQ(str1, res);
}

TEST(Arithmetic, can_parse_and_calculate_correctly)
{
	string str = "10*(25/5)-(1025+40)";

	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(-1015, res);
}

TEST(Arithmetic, can_parse_and_calculate_correctly1)
{
	string str = "5/2*(12-6+4)+(24/4)";
	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(31, res);
}

TEST(Arithmetic, can_parse_and_calculate_correctly2)
{
	string str = "123456789-987654321";
	double val = 123456789 - 987654321;
	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(val, res);
}

TEST(Arithmetic, can_parse_and_calculate_correctly3)
{
	string str = "0.5*12+44/11";

	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(10, res);
}

TEST(Arithmetic, can_parse_and_calculate_correctly4)
{
	string str = "(12.223-0.223)+(289.1*10)";

	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(2903, res);
}

TEST(Arithmetic, can_parse_and_calculate_correctly5)
{
	string str = "(5-5-5-5+5+5+5)*(5-5-5-5)";

	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(-50, res);
}