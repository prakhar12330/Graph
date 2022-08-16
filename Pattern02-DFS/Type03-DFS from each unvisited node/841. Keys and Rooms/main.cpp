class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,vector<bool>&visited,int roomNo)
    {
        visited[roomNo]=true;
        for(auto it:rooms[roomNo])
        {
            if(!visited[it])
            {
                dfs(rooms,visited,it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size();
        vector<bool>visited(n,false);
        //Make An DFS Call From room0
        dfs(rooms,visited,0);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])return false;
        }
        return true;
    }
};
