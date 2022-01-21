#include <iostream>
#include <cstdlib>
#include "queue.h"
#include <map>
#include <vector>

std::map<int, int> visited;
std::vector<int> list[50];
queue q;

void bfs(int n)
{
	q.enqueue(n);
	while(!q.checkempty())
	{
		for(int mem : list[n])
		{
			if(!visited[mem])
			{
				q.enqueue(mem);
			}
		}
		visited[n] = n;
		std::cout<<q.dequeue()<<std::endl;
		if(!q.checkempty()) n = q.qfront();
	}
}

int main()
{
	int p,q,start,num;
	std::cout<<"Enter the number of adjacency list members:"<<std::endl;
	std::cin>>num;
	std::cout<<"Enter the adjacency list members of directed graph:"<<std::endl;
	for(int i=0; i<num; i++)
	{
		std::cin>>p>>q;
		list[p].push_back(q);
	}

	std::cout<<"Enter the node to search from"<<std::endl;
	std::cin>>start;
	bfs(start);
	return 0;
}