#include "pch.h"
#include "iostream"
//#include "stack"
using namespace std;
template <class t> class Stack;
template <class t> Stack<t> merge(const Stack<t> & s1, const Stack <t> & s2);
template <class t> class Stack {
private:
	t *stackArr; 
	int size;
	int top;
public:
	Stack(int k) {
		this->size = k;
		this->stackArr = new t[size];
		this->top = 0;
	}
	
	Stack(const Stack& s) {
		this->size = s.size;
		this->stackArr = new t[size];
		copy(s.stackArr, s.stackArr + s.size, this->stackArr);
		this->top = s.top;
	}

	void push(t element) 
	{
		if (this->top >= this->size)
			throw new exception("Stack is full");
		else { 
			stackArr[this->top] = element;
			top++;
		}
	}

	void pop()
	{
		if (this->top <= 0)
			throw new exception("Stack is empty");
		stackArr[this->top] = 0;
		top--;
	}

	void print()
	{
		for (int i = 0; i < top; i++)
			cout << stackArr[i] << " ";
		cout << endl;
	}
	friend Stack merge<t>(const Stack<t> & s1, const Stack <t> & s2);

	~Stack() {	delete[] stackArr;	}
};
template<class t>
Stack<t> merge(const Stack<t> & s1, const Stack <t> & s2) {
	int size = s1.size + s2.size;
	Stack<t> stack = Stack<t>(size);
	int i = 0;
	while (i != s1.top) {
		stack.push(s1.stackArr[i]);
		i++;
	}
	i = 0;
	while (i != s2.top) {
		stack.push(s2.stackArr[i]);
		i++;
	}
	return stack;
}
