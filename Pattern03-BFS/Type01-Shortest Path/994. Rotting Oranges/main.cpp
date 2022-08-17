class Solution {
public:
    int di[4]={1,-1,0,0};
    int dj[4]={0,0,1,-1};
    
    bool isValid(int row,int col,int m,int n)
    {
        if(row<0||col<0||row>=m||col>=n)return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        
        int frshOrng=0; //To keep track of all fresh oranges left at the end (while returning answer)
        
        //Traversing Over The grid and pushing the coordinates of the rooten oranges into queue
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    frshOrng++;
            }
        }
        
        int mnts=0;
        while(!q.empty())
        {
            mnts++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                   if(isValid(x+di[k],y+dj[k],m,n)&&grid[x+di[k]][y+dj[k]]==1)
                   {
                      grid[x+di[k]][y+dj[k]]=2;
                      q.push({x+di[k],y+dj[k]});
                      frshOrng--;
                   }
                }
            }
        }  
        
        if(frshOrng>0)return -1;
        if(mnts>=1)return mnts-1;
        return 0;
     
    }
};
