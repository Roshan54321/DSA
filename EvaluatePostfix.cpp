#include <iostream>
#define SIZE 20

std::string postfix;

class stack
{
        int array[SIZE];
        int top;

public:
        stack()
        {
                top = -1;
        }
        void push(int element)
        {
                if (top == SIZE - 1)
                {
                        std::cout << "stack Overflow!!" << std::endl;
                        exit(1);
                }

                array[++top] = element;
        }

        void pop()
        {
                if (top == -1)
                {
                        std::cout << "stack Underflow!!" << std::endl;
                        exit(1);
                }

                top--;
        }

        int Size()
        {
                return top++;
        }

        int peek()
        {
                return array[top];
        }
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

void Evaluate(stack &s)
{
        char c;
        float result;
        for (int i = 0; i < postfix.length(); i++)
        {
                c = postfix[i];
                if (CheckOperator(c))
                {
                        int a = s.peek() - '0';
                        s.pop();
                        int b = s.peek() - '0';
                        s.pop();
                        switch (c)
                        {
                        case '+':
                        {
                                result = a + b;
                                break;
                        }
                        case '-':
                        {
                                result = b - a;
                                break;
                        }
                        case '*':
                        {
                                result = b * a;
                                break;
                        }
                        case '/':
                        {
                                result = b / a;
                                break;
                        }
                        case '^':
                        {
                                result = b ^ a;
                                break;
                        }
                        default:
                        {
                                break;
                        }
                        }
                        char temp = result + '0';
                        s.push(temp);
                }
                else
                {
                        s.push(c);
                }
        }
        std::cout << "The Result of this expression is : " << s.peek() - '0' << std::endl;
}

int main()
{
        std::cout << "Enter The Postfix Expression: " << std::endl;
        std::cin >> postfix;
        stack s;
        Evaluate(s);

        return 0;
}
