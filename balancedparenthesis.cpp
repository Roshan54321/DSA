#include <iostream>
#include <cstring>

template <class T>
class stack
{
    int top;
    T* array;
    int n;
public:
    stack()
    {
        n = 20;
        top = -1;
        array = new T[n];
    }

    void push(T data)
    {
        array[++top] = data;
    }

    T pop()
    {
        return array[top--];
    }
    
    bool empty()
    {
        if(top == -1) return true;
        return false;
    }
};

int main()
{
    stack<char> s;
    char* str = (char*)"sdfs(dfs)d()";
    for(int i = 0; i<strlen(str); i++)
    {
        if(str[i] == '(' )
        {
            s.push('(');
        }

        if(str[i] == ')')
        {
            if(s.empty())
            {
                std::cout<<"Parenthesis are not balanced"<<std::endl;
                return 0;
            }
            s.pop();
        }
    }

    if(s.empty())
    {
        std::cout<<"Parenthesis are balanced"<<std::endl;
    }
    else
    {
        std::cout<<"Parenthesis are not balanced"<<std::endl;
    }

    return 0;
}