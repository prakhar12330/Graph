//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool checkCycle(vector<int> adj[],vector<bool>&visited, vector<bool>&recCall,int src)
    {
        visited[src]=true;
        recCall[src]=true;
        for(auto i:adj[src])
        {
            if(visited[i]==false)
            {
                if(checkCycle(adj,visited,recCall,i))
                {
                    return true;
                }
            }
            else if(recCall[i])
            {
                return true;
            }
        }
        recCall[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool>visited(V,false);
        vector<bool>recCall(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(checkCycle(adj,visited,recCall,i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
