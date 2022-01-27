#include <iostream>
#define SIZE 20

std::string postfix;
std::string infix;

class stack
{
	char array[SIZE];
	int top;

public:
	stack()
	{
		top = -1;
	}
	void push(char element)
	{
		if (top == SIZE - 1)
		{
			std::cout << "stack Overflow!!" << std::endl;
		}
		top += 1;
		array[top] = element;
	}

	void pop()
	{
		if (top == -1)
		{
			std::cout << "stack Underflow!!" << std::endl;

		}
		else
		{
			top--;
		}
	}

	int Size()
	{
		return top + 1;
	}

	char topElement()
	{
		return array[top];
	}

	bool empty()
	{
		if(top == -1) return 1;
		return 0;
	}

	friend void Convert();
	friend int CheckPriority();
};

bool CheckOperator(char ch)
{
	if ((ch == '*') || (ch == '+') || (ch == '-') || (ch == '/') || (ch == '^'))
	{
		return true;
	}
	else
		return false;
}

int CheckPriority(char ch)
{
	if ((ch == '+') || (ch == '-'))
		return 3;
	else if ((ch == '*') || (ch == '/'))
		return 2;
	else if (ch == '^')
		return 1;
	else
		return 4;
}

void Convert(stack s)
{
	char c;
	if (s.empty())
	{
		s.push('(');
	}

	for (int i = 0; i <= infix.length(); i++)
	{
		if (i == infix.length())
			c = ')';
		else
			c = infix[i];
		if (CheckOperator(c))
		{
			if (CheckOperator(s.topElement()))
			{
				if (CheckPriority(c) >= CheckPriority(s.topElement()))
				{
					postfix += s.topElement();
					s.pop();
				}
			}
			s.push(c);
		}
		else if (c == '(')
		{
			s.push(c);
		}
		else if (c == ')')
		{
			while (s.topElement() != '(')
			{
				postfix += s.topElement();
				s.pop();
			}
			s.pop();
		}
		else
		{
			postfix += c;
		}
	}
	std::cout << "Result:" << postfix << std::endl;
}

int main()
{
	std::cout << "Enter The Infix Expression" << std::endl;
	std::cin >> infix;
	stack s;
	Convert(s);
	return 0;
}
