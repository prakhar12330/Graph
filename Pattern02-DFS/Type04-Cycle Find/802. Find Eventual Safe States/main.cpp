class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<bool>&visited,vector<bool>&dfsVisited,vector<bool>&notsafeNode,int node)
    {
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto it:graph[node])
        {
            if(!visited[it])
            {
                if(dfs(graph,visited,dfsVisited,notsafeNode,it))
                {
                    notsafeNode[node]=true;
                    return true;
                }
            }
            else if(visited[it]&&dfsVisited[it])
            {
                notsafeNode[node]=true;
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
        vector<bool>notsafeNode(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(graph,visited,dfsVisited,notsafeNode,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!notsafeNode[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
