// #include <iostream>
// #include <cstdlib>
// #include <vector>
// #include <map>


// std::vector<char> list[50];
// std::map<char, char> visited;
// char p,q,start;
// int num;

// void dfs(char n)
// { 
// 	// if(visited[n])
// 	// { 
// 	// 	std::cout<<"visited "<<n<<std::endl;              //time: O(V+E)
// 	// 	return;  										  //space: O(V)	
// 	// } 
	
// visited[n] = n; 
// 	std::cout<<n<<std::endl;  //pre order 
 //    for(char x :list[n])
	// { 
	// 	if(!visited[x]) dfs(x); 
	// }
	
// 	//std::cout<<n<<std::endl;  //post order
// }

// int main()
// {
// 	std::cout<<"Enter the number of adjacency list members:"<<std::endl;
// 	std::cin>>num;
// 	std::cout<<"Enter the adjacency list members of directed graph:"<<std::endl;

// 	for(int i=0; i<num; i++)
// 	{
// 		std::cin>>p>>q;
// 		list[p].push_back(q);
// 	}

// 	std::cout<<"Enter the node to search from"<<std::endl;
// 	std::cin>>start;
// 	dfs(start);
// 	return 0;
// }


//using stack
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>


std::vector<char> list[50];
std::map<char, char> visited;
std::vector<char> stack;
char p,q,start;
int num;

void dfs(char n)
{ 
	stack.push_back(n);
	while(!stack.empty())
	{
		n = stack.back();
		stack.pop_back();
		if(!visited[n]) 
		{
			std::cout<<n<<std::endl;  //pre order 
	    	visited[n] = n; 		
		}

		for(char i : list[n])
		{
			if(!visited[i]) stack.push_back(i);
		}
	}
	//std::cout<<n<<std::endl;  //post order
}

int main()
{
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
	dfs(start);
	return 0;
}