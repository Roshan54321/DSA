#include <iostream>
#include <cstdlib>

template <class T>
class circularqueue
{
    int front;
    int rear;
    T* array;
    int n;
public:
    circularqueue()
    {
        std::cout <<"Enter the size of queue"<< std::endl;
        std::cin >> n;
        array = new T[n];
        front = -1;
        rear = -1;
    }

    void enqueue(T data)
    {
        if((front == 0 && rear == n - 1) || rear == front - 1)
        {
            std::cout << "Overflow!!" <<std::endl;
        }
        else if(front == -1)
        {
            front++;
            rear++;
            array[rear] = data;
        }
        else
        {
            if(front > 0 && rear == n)
            {
                rear = 0;
                array[rear] = data;
            }
            else
            {
                rear++;
                array[rear] = data;
            }
        }
    }

    T dequeue()
    {
        T data;
        if(front == -1)
        {
            std::cout <<"Queue is empty" <<std::endl;
            exit(0);
        }

        data = array[front];

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            if(front = n-1) front = 0;
            else front++;
        }
        return data;
    }

    void display()
    {
        if(front == -1)
        {
            std::cout <<"Queue is empty!!" <<std::endl;
        }
        else
        {
            int i = front;
            while(i != rear)
            {
                std::cout <<array[i]<< "  ";
                i++;
            }
            std::cout <<array[i]<< std::endl;

        }
    }
};


int main()
{
    circularqueue<int> q;
    q.enqueue(2);
    q.display();
    q.dequeue();
    q.display();
    
    return 0;
}