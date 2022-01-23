//this is only for directed acyclic graph(DAG)
#include <iostream>
#include <list>
#include <stack>
#include <map>


std::list<int> list[100];
std::stack<int> stack;
std::map<int, int> visited;


template <class T>
void DFS(T n)
{
    visited[n]  = 1;
    for(T mem : list[n])
    {
        if(!visited[mem])
        {
            DFS(mem);
        }
    }
    stack.push(n);
}

int main()
{
    int n, x, y, start;
    std::cout<<"Enter the number of adjacency list members"<<std::endl;
    std::cin>>n;
    std::cout<<"Input the adjacency list"<<std::endl;
    for(int i = 0; i<n; i++)
    {
        std::cin>>x>>y;
        list[x].push_back(y);
    }
    std::cout<<"Enter the starting node of the search"<<std::endl;
    std::cin>>start;

    DFS(start);

    while(!stack.empty())
    {
        std::cout<<stack.top()<<std::endl;
        stack.pop();
    }

    return 0;
}