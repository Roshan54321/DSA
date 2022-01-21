#include <iostream>
#include <cstdlib>
#include "queue.h"

queue::queue()
{
	front = -1;
	rear = -1;
	std::cout<<"Enter the size of queue"<<std::endl;
	std::cin>>n;
	array =  new int(n);
}

void queue::enqueue(int data)
{
	if(rear >= n-1)
	{
		std::cout<<"Overflow!!"<<std::endl;
		exit(1);
	}
	else
	{
		if(front == -1) front = 0;
		rear++;
		array[rear] = data;
		// std::cout<<data<<" is added"<<std::endl;
	}
}

int queue::dequeue()
{
	if(front == -1 || front>rear)
	{
		std::cout<<"Underflow!!"<<std::endl;
		exit(1);
	}
	else
	{
		return array[front++];
	}
}

int queue::qfront()
{
	if(front == -1 || front>rear)
	{
		std::cout<<"Empty!!"<<std::endl;
		exit(1);
	}
	else
	{
		return array[front];
	}
}

void queue::displayall()
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

bool queue::checkempty()
{
	if(front == -1 || front>rear)
	{
		return 1;
	}
	return 0;
}


// int main()
// {
// 	queue q;
// 	q.enqueue(4);
// 	q.enqueue(3);
// 	q.enqueue(5);
// 	std::cout<<q.dequeue()<<std::endl;
// 	q.displayall();

// 	return 0;
// }