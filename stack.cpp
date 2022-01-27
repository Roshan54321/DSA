#include <iostream>
#include <cstdlib>
#define SIZE 20

template <class T>
class stack
{
	T* array;	
	int top;

public:
	stack()
	{
		top = -1;
		array = new T[SIZE];
	}

	void push(T element)
	{
		if(top == SIZE - 1)
		{
			std::cout<<"Stack Overflow!!"<<std::endl;
			exit(1);
		}
		else
		{
			array[++top] = element;
		}
	}

	void pop()
	{
		if(top == -1)
		{
			std::cout<<"Stack Underflow!!"<<std::endl;
			exit(1);
		}
		top--;
	}

	int size()
	{
		return top + 1;
	}

	T peek()
	{
		return array[top];
	}
};

int main()
{
	stack<int> s;
	s.push(9);
	s.push(11);
	s.push(12);
	s.pop();
	s.pop();
	s.push(10);
	s.pop();
	std::cout << s.peek() << std::endl;

	return 0;
}
