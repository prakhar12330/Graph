class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,int m,int n)
    {
        //Base Case-->
        if(row<0 or col<0 or row>=m or col>=n or grid[row][col]!=1)return;
        grid[row][col]='#';
        dfs(grid,row-1,col,m,n);
        dfs(grid,row+1,col,m,n);
        dfs(grid,row,col-1,m,n);
        dfs(grid,row,col+1,m,n);
        
    }
    int numEnclaves(vector<vector<int>>& grid)
    {
        
        int m=grid.size();//No. Of Rows
        int n=grid[0].size();//No. Of Columns
        
        if(m==0)return 0;
        
        //Traversing The First Column And Last Column
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(grid,i,0,m,n);
            }
            if(grid[i][n-1]==1)
            {
                dfs(grid,i,n-1,m,n);
            }
        }
         //Traversing The First Row And Last Row
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1)
            {
                dfs(grid,0,j,m,n);
            }
            if(grid[m-1][j]==1)
            {
                dfs(grid,m-1,j,m,n);     
            }
        }
        int landCellCount=0;
        //Traversing Over The Board and doing the appropriate
        for(int i=0; i<m; i++)
        {
          for(int j=0; j<n; j++)
          {
             if(grid[i][j] == 1)
             {
                 landCellCount++;
             }
    
          }
        }
        return landCellCount;
    }
};
