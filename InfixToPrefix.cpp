#include <iostream>
#define SIZE 20

class stack
{
        char arr[SIZE];
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
                        exit(1);
                }

                arr[++top] = element;
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

        char peek()
        {
                return arr[top];
        }

        bool empty()
        {
                if(top == -1) return 1;
                return 0;
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

std::string reverse(std::string input)
{
        for (int i = 0; i < (input.length() / 2); i++)
        {
                std::swap(input[i], input[input.length() - i - 1]);
        }
        return input;
}

std::string OpenToClose(std::string str)
{
        for (int i = 0; i < str.length(); i++)
        {
                if (str[i] == '(')
                {
                        str[i] = ')';
                }
                else if (str[i] == ')')
                {
                        str[i] = '(';
                }
        }
        return str;
}

std::string convert(stack &s, std::string str)
{
        std::string postfix;
        char c;
        if (s.empty())
        {
                s.push('(');
        }
        for (int i = 0; i <= str.length(); i++)
        {
                if (i == str.length())
                        c = ')';
                else
                        c = str[i];
                if (CheckOperator(c))
                {
                        if (CheckOperator(s.peek()))
                        {
                                if (CheckPriority(c) >= CheckPriority(s.peek()))
                                {
                                        postfix += s.peek();
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
                        while (s.peek() != '(')
                        {
                                postfix += s.peek();
                                s.pop();
                        }
                        s.pop();
                }
                else
                {
                        postfix += c;
                }
        }
        return postfix;
}

int main()
{
        stack s;
        std::string infix, prefix, postfix, reversed_infix, opentoclose;
        std::cout << "Enter The Infix Expression: " << std::endl;
        std::cin >> infix;

        reversed_infix = reverse(infix);
        opentoclose = OpenToClose(reversed_infix);
        postfix = convert(s, opentoclose);
        prefix = reverse(postfix);

        std::cout << "The equivalent prefix expression is: " << prefix << std::endl;;

        return 0;
}