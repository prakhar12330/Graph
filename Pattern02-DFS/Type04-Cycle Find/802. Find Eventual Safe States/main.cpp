class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<bool>&visited,vector<bool>&dfsVisited,vector<bool>&cycle,int node)
    {
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto it:graph[node])
        {
            if(!visited[it])
            {
                if(dfs(graph,visited,dfsVisited,cycle,it))
                {
                    cycle[node]=true;
                    return true;
                }
            }
            else if(visited[it]&&dfsVisited[it])
            {
                cycle[node]=true;
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<bool>dfsVisited(n,false);
        vector<bool>cycle(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(graph,visited,dfsVisited,cycle,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!cycle[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
