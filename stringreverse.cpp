#include <iostream>
#include <cstdlib>
#include <string>
#define SIZE 20

std::string input;
std::string reversed;

template <class T>
class stack
{
    int top;
    T* array;
    int n;
public:
    stack()
    {
        n = SIZE;
        top = -1;
        array = new T[n];
    }

    void push(T data)
    {
        if(top == n - 1)
        {
            std::cout<<"Stack is full!!"<<std::endl;
            exit(1);
        }
        array[++top] = data;
    }

    T pop()
    {
        if(top == -1)
        {
            std::cout<<"Stack is empty!!"<<std::endl;
            exit(1);
        }
        return array[top--];
    }
    
    bool empty()
    {
        if(top == -1) return true;
        return false;
    }
};

void ReverseString(stack<char> &s)
{
	for(int i = 0;i<input.size();i++)
	{
		s.push(input[i]);
	}
	for(int i = 0;i<input.size();i++)
	{
		reversed += s.pop();
	}
}

int main()
{
	std::cout << "Enter The String to be Reversed: ";
	std::cin >> input;
	stack<char> s;
	ReverseString(s);
	std::cout <<"The Reversed String is: "<< reversed << std::endl;
	return 0;
}
	
