//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool isCyclic(int V, vector<int> adj[])
    {
        //indegree vector to store indegree of various elements
        vector<int>indegree(V,0);
        queue<int>q;
        
        //Finding the indegree of all the elements
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        //pushing the elements with indegree 0 into queue
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto e:adj[node])
            {
                indegree[e]--;
                if(indegree[e]==0)
                {
                    q.push(e);
                }
            }
        }
        if(cnt==V)return false;
        else return true;
        
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
