// #include <iostream>
// #include <cstdlib>
// #include <vector>
// #include <map>
// #include <queue>

// std::vector<int> visited[100];
// std::vector<int> obs[100];

// int grid[4][4];
// std::vector<int> stackx;
// std::vector<int> stacky;
// std::queue<int> queuex;
// std::queue<int> queuey;
// std::queue<int> routex;
// std::queue<int> routey;

// void obstackle()
// {
// 	int arrx[] = {1,1,2,3};
// 	int arry[] = {1,2,2,0};
// 	int arrSize = sizeof(arrx)/sizeof(arrx[0]);
// 	for(int i = 0; i < arrSize; i++) 
// 		obs[arrx[i]].push_back(arry[i]); 
// }

// void recruit_grid()
// {
// 	grid[0][0] = 1;
// 	for(int i = 1; i<4; i++)
// 	{
// 			grid[i][0] = grid[i-1][0] + maxx;
// 	}

// 	for(int i = 0; i<4; i++)
// 	{
// 		for(int j = 1; j<4; j++)
// 		{
// 			grid[i][j] = grid[i][j-1] + 1;
// 		}
// 	}	
// }

// void bfs(int x, int y)
// {
// 	queuex.push(x);
// 	queuey.push(y);
// 	visited[x].push_back(y);
// 	while(!queuex.empty())
// 	{
// 		int checkx = 0;
// 		int checky = 0;
// 		routex.push(queuex.front());
// 		if(queuex.front() == 3) checkx = 1;
// 		queuex.pop();
// 		routey.push(queuey.front());
// 		if(queuey.front() == 3) checky = 1;
// 		queuey.pop();
// 		if(checkx && checky)
// 		{
// 			return;
// 		}
// 		x = queuex.front();
// 		y = queuey.front();

// 		for(int i=-1; i<=1; i++)
// 		{
// 			for(int j=-1; j<=1; j++)
// 			{
// 				if(std::abs(i) == std::abs(j)) continue;
// 				if(x+i < 0 || x+i > 3 || y+j < 0 || y+j > 3) continue;
// 				if(!visited[x+i].empty())
// 				{
// 					for(int mem : visited[x+i])
// 					{
// 						if((y+j) == mem) continue; 
// 					}
// 				}

// 				if(!obs[x+i].empty())
// 				{
// 					for(int mem : obs[x+i])
// 					{
// 						if((y+j) == mem) continue; 
// 					}

// 				}
// 				queuex.push(x+i);
// 				queuey.push(y+j);
// 				visited[x+i].push_back(y+j);
// 			}
// 		}
// 	}
// }

// int main()
// {
// 	obstackle();
// 	recruit_grid();
// 	bfs(0, 0);
// 	while(!routex.empty())
// 	{
// 		std::cout<<grid[routex.front()][routey.front()]<<std::endl;
// 		routex.pop();
// 		routey.pop();
// 	}
// 	return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>
#define maxx 8
#define maxy 8

int visited[maxx][maxy];
int obs[maxx][maxy];
int grid[maxx][maxy];
void obstackle()
{
	int arrx[] = {1,1,2,3,0,1,1,2,3,4,5,5,6,6,7};
	int arry[] = {1,2,2,0,4,4,6,4,6,3,6,7,1,5,3};
	int arrSize = sizeof(arrx)/sizeof(arrx[0]);
	for(int i = 0; i < arrSize; i++) 
		obs[arrx[i]][arry[i]] = 1;
}

void recruit_grid()
{
	grid[0][0] = 1;
	for(int i = 1; i<maxx; i++)
	{
			grid[i][0] = grid[i-1][0] + maxx;
	}

	for(int i = 0; i<maxx; i++)
	{
		for(int j = 1; j<maxy; j++)
		{
			grid[i][j] = grid[i][j-1] + 1;
		}
	}	
}


std::queue<std::pair<int, int>> queue;
std::list<std::pair<int, int>> route;
std::map<std::pair<int, int>, std::pair<int, int>> prev;
void bfs(int x, int y)
{
	queue.push({x, y});
	visited[x][y] = 1;
	while(!queue.empty())
	{
		std::pair<int, int> temp = queue.front();
		route.push_back(queue.front());
		if(temp.first == maxx-1 && temp.second == maxy-1)
		{
			return;
		}
		x = temp.first;
		y = temp.second;
		queue.pop();

		//checking neighbours
		for(int i=-1; i<=1; i++) 
		{
			for(int j=-1; j<=1; j++)
			{
				if(std::abs(i) == std::abs(j)) continue;
				if(x+i < 0 || x+i > maxx-1 || y+j < 0 || y+j > maxy-1) continue;
				if(visited[x+i][y+j])
				{
					continue; 
				}

				if(obs[x+i][y+j])
				{
					continue; 
				}

				queue.push({x+i,y+j});
				visited[x+i][y+j] = 1;
				std::pair<int, int> t = {x+i, y+j};
				prev[t] = {x, y};
			}
		}
	}
}

int main()
{
	obstackle();
	recruit_grid();
	bfs(0,0);

	route.reverse();
	std::stack<std::pair<int, int>> ans;
	std::list<std::pair<int, int>>::iterator it;
	it = route.begin();
	ans.push(*it);
	it++;
	for(it; it!= route.end(); it++)
	{
		if(*it == prev[ans.top()])
		{
			ans.push(*it);	
		}
	}

    while(!ans.empty())
	{
		std::pair<int, int> temp = ans.top();
		ans.pop();
		std::cout<<grid[temp.first][temp.second]<<std::endl;
	}
	return 0;
}