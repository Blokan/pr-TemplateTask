#include "pch.h"
#include <iostream>
#include "Stack.cpp"

int main()
{
	int size = 10;
	Stack<int> stack1(size);
	for (int i = 1; i <=size;i++)
		stack1.push(i);
	stack1.pop();
	stack1.print();
	Stack<int> stack2(size);
	for (int i = size; i >= 1; i--)
		stack2.push(i);
	stack2.print();
	Stack<int> stack3 = merge(stack1, stack2);
	stack3.print();
	stack3.pop();
	stack3.push(4);
	stack3.print();
	system("pause");
}
