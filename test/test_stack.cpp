// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> s(5));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-5));
}

TEST(Stack, can_create_copied_stack)
{
	Stack<int> s1(5);
	ASSERT_NO_THROW(Stack<int> s2(s1));
}

TEST(Stack, can_get_top_element_of_stack)
{
	Stack<int> s;

	s.Push(123);
	int s_element = s.Top();

	EXPECT_EQ(123, s_element);
}

TEST(Stack, can_add_elements_in_stack)
{
	Stack<int> s1;

	s1.Push(123);
	int s1_element = s1.Top();

	EXPECT_EQ(123, s1_element);
}

TEST(Stack, can_get_size)
{
	int const size = 10;
	Stack<int> s1;
	for (int i = 0; i < size; i++)
	{
		s1.Push(i);
	}

	EXPECT_EQ(size, s1.size());
}

TEST(Stack, can_assign_stack_to_itself)
{
	int const size = 10;
	Stack<int> s1;
	for (int i = 0; i < size; i++)
	{
		s1.Push(i);
	}

	ASSERT_NO_THROW(s1 = s1);
}

TEST(Stack, can_check_is_empty)
{
	int const size = 10;
	Stack<int> s1;
	for (int i = 0; i < size; i++)
	{
		s1.Push(i);
	}

	bool s1_empty = s1.IsEmpty();

	EXPECT_NE(true, s1_empty);
}

TEST(Stack, can_pop_elements_from_stack)
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);

	bool first = s1.IsEmpty();

	s1.Pop();
	s1.Pop();
	s1.Pop();

	bool last = s1.IsEmpty();

	EXPECT_NE(first, last);
}

TEST(Stack, cant_pop_elements_from_empty_stack)
{
	Stack<int> s1;
	ASSERT_ANY_THROW(s1.Pop());
}

TEST(Stack, cant_get_top_element_from_empty_stack)
{
	Stack<int> s1;
	ASSERT_ANY_THROW(s1.Top());
}

