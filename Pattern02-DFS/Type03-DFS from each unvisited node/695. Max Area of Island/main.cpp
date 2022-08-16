class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int row,int col,int m,int n)
    {
        if(row<0 || col<0|| col>=n||row>=m ||grid[row][col]==0||vis[row][col])return 0;
        
        vis[row][col]=true;
        
        return 1 + dfs(grid,vis,row-1,col,m,n) + dfs(grid,vis,row+1,col,m,n)  + dfs(grid,vis,row,col-1,m,n)  +        dfs(grid,vis,row,col+1,m,n) ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m=grid.size();//No. Of Rows
        int n=grid[0].size();//No Of Columns
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 and !vis[i][j])
                {
                    ans=max(ans,dfs(grid,vis,i,j,m,n));
                }
            }
        }
        return ans;
    }
};
