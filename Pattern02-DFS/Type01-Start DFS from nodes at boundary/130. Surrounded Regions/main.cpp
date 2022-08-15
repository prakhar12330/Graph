class Solution {
public:
    
    void dfs(vector<vector<char>>& board,int row,int col,int m,int n)
    {
        //Base Case-->
        if(row<0 or col<0 or row>=m or col>=n or board[row][col]!='O')return;
        board[row][col]='#';
        dfs(board,row-1,col,m,n);
        dfs(board,row+1,col,m,n);
        dfs(board,row,col-1,m,n);
        dfs(board,row,col+1,m,n);
        
    }
    void solve(vector<vector<char>>& board)
    {
        int m=board.size();//No. Of Rows
        int n=board[0].size();//No. Of Columns
        
        if(m==0)return;
        
        //Traversing The First Column And Last Column
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,i,0,m,n);
            }
            if(board[i][n-1]=='O')
            {
                dfs(board,i,n-1,m,n);
            }
        }
         //Traversing The First Row And Last Row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(board,0,j,m,n);
            }
            if(board[m-1][j]=='O')
            {
                dfs(board,m-1,j,m,n);     
            }
        }
        //Traversing Over The Board and doing the appropriate
        for(int i=0; i<m; i++)
        {
          for(int j=0; j<n; j++)
          {
             if(board[i][j] == 'O')
             {
                 board[i][j] = 'X';
             }
             if(board[i][j] == '#')
             {
                 board[i][j] = 'O';
             }
          }
        }
    }
};
