//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool BFS(vector<int> adj[], vector<bool> &visited, int src)
    {
        queue<pair<int,int>>q;
        
        q.push({src,-1});//inserting the src Node in the queue
        visited[src]=true;//marking visited array corresponding to src value true because it has been visited
        
        while(!q.empty())
        {
            int x=q.front().first;//getting the node value 
            int parent=q.front().second;
            
            q.pop();
            for(auto i:adj[x])
            {
                
                if(visited[i]==false)
                {
                    visited[i]=true;
                    q.push({i,x});
                }
                else if(i!=parent)
                {
                    return true;
                }
            }
            
            
        }
        return false;
    }
    
    bool checkBFS(int V,vector<int> adj[])
    {
        vector<bool>visited(V,false);//Index Of The Visited Array Will Be Considered As Nodes
        //Traversing over all nodes to handle the component problem of graph
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(BFS(adj,visited,i))//i refers to a node
                {
                    return true;
                }
            }
        }
    
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        return checkBFS(V,adj);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
