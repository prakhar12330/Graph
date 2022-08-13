//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function for finding the dfs of transpose graph
	void revDFS(int node,vector<int> &vis,vector<int> transpose[])
    {
    vis[node]=1;
    for(auto i:transpose[node])
    {
        if(!vis[i])
        {
            revDFS(i,vis,transpose);
        }
    }
    }
	//Function for finding Topological Sort
	void dfs(int node,stack<int>&st,vector<int>&visited,vector<int> adj[])
	{
	    visited[node]=1;
       for(auto i : adj[node])
       {
           if(!visited[i])
           {
               dfs(i,st,visited,adj);
           }
       }
       st.push(node);
	}
	//Kosaraju's Algorithm-->Algorithm For Finding The Strongly Connected Components
	
    int kosaraju(int V, vector<int> adj[])
    {
        //Step01-->Finding The Topological Sort
        vector<int>visited(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,st,visited,adj);
            }
        }
        //Step02-->Transposing the graph
        vector<int>transpose[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto it:adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        //Step03-->Do The DFS
        int countSCC=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!visited[node])
            {
                revDFS(node,visited,transpose);
                countSCC++;
            }
        }
        return countSCC;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
