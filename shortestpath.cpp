#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <limits>

std::map<std::pair<int, int>, int> mapping;
std::list<int> list[100];
std::map<int, int> visited;
std::list<int> topsorted;
int dist[30];


template <class T>
void dfs(T n)
{ 
    visited[n] = 1;
    for(T mem : list[n])
    {
        if(!visited[mem])
        {
            dfs(mem);
        }
    }
    topsorted.push_back(n);
}

void shortestpath()
{
     for(int mem : topsorted)
     {
         if(mem == topsorted.front())
         {
             dist[mem] = 0;
         }

         for(int n : list[mem])
         {
             if(mapping[{mem, n}] + dist[mem] < dist[n])
             {
                 dist[n] = mapping[{mem, n}] + dist[mem];
             }
         }
     }
}

int main()
{
    for(int i = 0; i<30; i++)
    {
        dist[i] = std::numeric_limits<int>::max();
    }
    int n;
    std::cout <<"Enter the number of adjacency list members"<< std::endl;
    std::cin>>n;
    std::cout <<"Enter the adjacency list members with their edge weights"<< std::endl;
    for(int i = 0; i<n; i++)
    {
        int x, y, z;
        std::cin>>x>>y>>z;
        mapping[{x, y}] = z;
        list[x].push_back(y);
    }
    int start;
    std::cout <<"Enter the starting node" <<std::endl;
    std::cin >> start;
    dfs(start);
    topsorted.reverse();
    // for(std::list<int> :: iterator it = topsorted.begin(); it != topsorted.end(); it++)
    // {
    //     std::cout << *it <<std::endl;
    // }
    shortestpath();
    for(std::list<int> :: iterator it = topsorted.begin(); it != topsorted.end(); it++)
    {
        std::cout << dist[*it] <<std::endl;
    }

    return 0;
}





// //Dijkstra's Algorithm using priority queue
// #include <iostream>
// #include <queue>
// #include <map>
// #include <list>
// #include <limits>

// class func
// {
// public:
//     int operator()(std::pair<int, int> &p, std::pair<int, int> &q)
//     {
//         return p.second< q.second;
//     }
// };

// std::priority_queue<std::pair<int, int>, std::vector<int>, func> queue;
// int dist[50];
// std::list<int> list;
// std::map<std::pair<int, int>, int> mapping;

// void shortestpath(int n)
// {
//      dist[n] = 0;
//      queue.push({n, dist[n]});
//      while(!queue.empty())
//      {
//          if(queue.top().second() > dist[queue.top().first()])
//          {
//              queue.pop();
//              continue;
//          }
//          std::pair<int, int> temp;
//          temp.first() = queue.top();
//          queue.pop();
//          for(mem : list[temp.first()])
//          {
//              queue.push(mem, temp.second() + mapping[{temp, mem}]);
//              dist[mem] = temp.second() + mapping[{temp, mem}];
//          }
//      }
// }

// int main()
// {
//     for(int i = 0; i<30; i++)
//     {
//         dist[i] = std::numeric_limits<int>::max();
//     }
//     int n;
//     std::cout <<"Enter the number of adjacency list members"<< std::endl;
//     std::cin>>n;
//     std::cout <<"Enter the adjacency list members with their edge weights"<< std::endl;
//     for(int i = 0; i<n; i++)
//     {
//         int x, y, z;
//         std::cin>>x>>y>>z;
//         mapping[{x, y}] = z;
//         list[x].push_back(y);
//     }
//     int start;
//     std::cout <<"Enter the starting node" <<std::endl;
//     std::cin >> start;

//     shortestpath(start);
//     for(std::list<int> :: iterator it = list.begin(); it != list.end(); it++)
//     {
//         std::cout << dist[*it] <<std::endl;
//     }

//     return 0;
// }