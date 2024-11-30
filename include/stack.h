#pragma once
#ifndef __Stack_
#define __Stack__

#include <vector>
#include <stdexcept>

template <typename T>
class Stack
{
private:
	int top;
	std::vector<T> mem;
public:
	Stack() : top(-1)
	{
	}

	Stack(size_t capacity) : top(-1)
	{
		mem.reserve(capacity);
	}

	~Stack() = default;

	size_t size() const
	{
		return top + 1;
	}
	bool IsEmpty() const
	{
		return mem.empty();
	}
	void Push(const T& val)
	{
		mem.push_back(val);
		top++;
	}
	void Pop()
	{
		if (IsEmpty())
			throw std::runtime_error("Cannot pop from an empty stack");
		mem.pop_back();
		top--;
	}
	T Top() const
	{
		if (IsEmpty())
			throw std::runtime_error("Stack is empty");
		return mem[top];
	}
};
#endif
