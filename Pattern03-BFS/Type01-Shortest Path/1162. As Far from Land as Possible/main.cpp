class Solution {
public:
    
    int di[4]={1,-1,0,0};
    int dj[4]={0,0,1,-1};
    
    bool isValid(int row,int col,int n)
    {
        if(row<0||col<0||row>=n||col>=n)return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid)
    {
        int n=grid.size();//No. Of Rows And Cols
        queue<pair<int,int>>q;
        
        //Pushing The Coordinates Of All Lands Present In The Grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        
        //If The Grid has no water cell return -1
        if(q.size()==n*n)return -1;
        
        int countDistance=0;
        while(!q.empty())
        {
            countDistance++;
            int currSize=q.size();
            for(int i=0;i<currSize;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                   if(isValid(x+di[k],y+dj[k],n)&&grid[x+di[k]][y+dj[k]]==0)
                   {
                      grid[x+di[k]][y+dj[k]]=1;
                      q.push({x+di[k],y+dj[k]});
                   }
                }
            }
        }
        return countDistance-1;
    }
};
