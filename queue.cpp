#include <iostream>
#include <cstdlib>

class queue
{
	int data;
	int* array;
	int front;
	int rear;
	int n;
public:
	queue()
	{
		front = -1;
		rear = -1;
		std::cout<<"Enter the size of queue"<<std::endl;
		std::cin>>n;
		array =  new int(n);
	}

	void enqueue(int data)
	{
		if(rear >= n-1)
		{
			std::cout<<"Overflow!!"<<std::endl;
			return;
		}
		else
		{
			if(front == -1) front = 0;
			rear++;
			array[rear] = data;
			std::cout<<data<<" is added"<<std::endl;
		}
	}

	void dequeue()
	{
		if(front == -1 || front>rear)
		{
			std::cout<<"Underflow!!"<<std::endl;
			return;
		}
		else
		{
			std::cout<<"Deleted "<<array[front]<<std::endl;
			front++;
		}
	}

	void displayall()
	{
		if(front == -1 || front>rear)
		{
			std::cout<<"Queue is empty!"<<std::endl;
			exit(0);
		}

		for(int i=front; i<=rear; i++)
		{
			std::cout<<array[i]<<" ";
		}
		std::cout<<std::endl;
	}
};


int main()
{
	queue q;
	q.enqueue(4);
	q.enqueue(3);
	q.enqueue(5);
	q.dequeue();
	q.displayall();

	return 0;
}