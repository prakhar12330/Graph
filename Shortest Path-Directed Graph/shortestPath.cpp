#include <iostream>
#include <list>
#include <unordered_map>
#include <stack> 
#include <vector>
#include <limits.h>




using namespace std;

class graph
{
    public:

   //unordered map to for making adj list
    unordered_map<int,list<pair<int,int>>>adj;
    void addEdge(int u,int v,int weight)
    {
         pair<int,int>p=make_pair(v,weight);
         adj[u].push_back(p);
    }
    void printAdjList()
    {
       for(auto it:adj)
       {
         cout<<it.first<<"->";
         for(auto j:it.second)
         {
           cout<<"{"<<j.first<<","<<j.second<<"},";
         }
         cout<<endl;
       }
    }
    void dfs(int src, unordered_map<int, bool>&visited,stack<int>&s)
    {
        visited[src]=true;
        for(auto it:adj[src])
        {
            if(visited[it.first] == 0)
           {
              dfs(it.first,visited,s);
           }
        }
        s.push(src);
         
    }
    void getShortestPath(int src,vector<int>&distance,stack<int>&s)
    {
        distance[src]=0;
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
           if(distance[x]!=INT_MAX)
           {
           for(auto it:adj[x])
           {
             if(distance[x]+it.second<distance[it.first])
             {
                 distance[it.first] = distance[x] + it.second;
             }
           }
           }
        }

    }
};
int main()
{
  graph g;
  g.addEdge(0,1,5);
  g.addEdge(0,2,3);
  g.addEdge(1,2,2);
  g.addEdge(1,3,6);
  g.addEdge(2,3,7);
  g.addEdge(2,4,4);
  g.addEdge(2,5,2);
  g.addEdge(3,4,-1);
  g.addEdge(4,5,-2);
  g.printAdjList();

  int n=6;//No.Of Nodes
  unordered_map<int,bool>visited;
  stack<int>s;
  for(int i=0;i<n;i++)
  {
     if(!visited[i])
     {
        g.dfs(i,visited,s);
     }
  }

  int src=1;
  vector<int>distance(n);
   for(int i=0;i<n;i++)
   {
    distance[i]=INT_MAX;
   }
   g.getShortestPath(src,distance,s);
   cout<< "Answer is-->"<<endl;
   for(int i=0;i<distance.size();i++)
   {
    cout<<distance[i]<<" ";
   }
  return 0;
}
