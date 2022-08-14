class Solution {
public:
    
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x])return x;
        return find(parent[x],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        vector<int>parent(n);
        int c=connections.size();
        if(c<n-1)return -1;//Connection not possible
        
           for(int i=0;i<n;i++)
           {
               parent[i]=i;
           }
        
        for(int i=0;i<c;i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            int prntu=find(u,parent);
            int prntv=find(v,parent);
            if(prntu!=prntv)
            {
                parent[prntv]=prntu;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                ans++;
            }
        }
        return ans-1;
    }
};
