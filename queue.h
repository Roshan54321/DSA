#ifndef QUEUE_H
#define QUEUE_H

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
	queue();
	void enqueue(int);
	int qfront();
	int dequeue();
	void displayall();
	bool checkempty();
};

#endif