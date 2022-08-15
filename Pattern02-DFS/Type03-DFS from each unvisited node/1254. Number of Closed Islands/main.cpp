class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int row,int col,int m,int n)
    {
        if(row<0||col<0||row>=m||col>=n||grid[row][col]==1||vis[row][col])return;
        
        vis[row][col]=true;
        dfs(grid,vis,row+1,col,m,n);
        dfs(grid,vis,row-1,col,m,n);
        dfs(grid,vis,row,col+1,m,n);
        dfs(grid,vis,row,col-1,m,n);
    }
    int closedIsland(vector<vector<int>>& grid)
    {
        int m=grid.size();//No. Of Rows
        int n=grid[0].size();//No. Of Columns
        
        int res=0;
        
        if(grid.empty())return 0;
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));//Visited Array
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==n-1||i==m-1||j==0)
                {
                    dfs(grid,vis,i,j,m,n);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 && !vis[i][j])
                {
                    dfs(grid,vis,i,j,m,n);
                    res++;
                }
            }
        }

        return res;
    }
};
