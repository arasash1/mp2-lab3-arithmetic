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
	string str = "10*(25/3030)-(2+40)";

	Arithmetic ar(str);
	double res = ar.pubCalculate();


	EXPECT_EQ(-1170, res);
}