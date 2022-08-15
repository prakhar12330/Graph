class Solution {
public:
    
    int dfs(int headID,vector<vector<int>>& adj,vector<int>& informTime)
    {
        int time=0;
        int node=headID;
        for(auto it:adj[node])
        {
            time=max(time,dfs(it,adj,informTime));
        }
        return informTime[node]+time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)continue;
            adj[manager[i]].push_back(i);
        }
        
        return dfs(headID,adj,informTime);
    }
};
