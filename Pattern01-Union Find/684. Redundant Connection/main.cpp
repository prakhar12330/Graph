class Solution {
public:
    
    int findParent(int x,vector<int>&parent)
    {
        if(x==parent[x])return x;
        
        return findParent(parent[x],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        vector<int>res;
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++)
        {
            parent[i]=i;
        }
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int prntu=findParent(u,parent);
            int prntv=findParent(v,parent);
            if(prntu==prntv)
            {
                res=it;
            }
            parent[prntu]=prntv;
        }
        
        return res;
    }
};
