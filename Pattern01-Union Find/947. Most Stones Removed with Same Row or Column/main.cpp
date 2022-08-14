class Solution {
public:
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x])return x;
        return find(parent[x],parent);
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int totalStones=stones.size();
        vector<int>parent(totalStones,0);
        for(int i=0;i<totalStones;i++)
        {
            parent[i]=i;
        }
        
        for (int i = 0; i < totalStones; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    int x = find(i,parent);
                    int y = find(j,parent);
                    if (x != y)
                        parent[y] = x;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < totalStones; i++) 
        {
            if (parent[i] == i)
                ans++;
        }
        
        return totalStones-ans;
    }
};
