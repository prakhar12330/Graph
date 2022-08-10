//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>s;//Taking A Set For Getting A Minimum Distance Node
        vector<int>dist(V,INT_MAX);
        
        dist[S]=0;//making a change in the distance array for source node
        s.insert({0,S});
        while(!s.empty())
        {
            auto node=s.begin();
            int distance = node->first;//distance
            int u = node->second;//node value
            s.erase(node);
            //traversing the neighbours
            for(auto &it:adj[u])
            {
                if(dist[u]+it[1]<dist[it[0]])
                {
                    if(dist[it[0]]!=INT_MAX)
                    {
                       s.erase({dist[it[0]],it[0]});
                    }
                    dist[it[0]] = dist[u]+it[1];
                    s.insert({dist[it[0]],it[0]});
                }
            }
        }
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
