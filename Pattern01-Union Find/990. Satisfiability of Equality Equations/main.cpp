class Solution {
public:
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x])return x;
        return find(parent[x],parent);
    }
    bool equationsPossible(vector<string>& equations) 
    {
        int n=equations.size();
        vector<int>parent(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if (equations[i][1] == '=') 
            {
                int prntu = find(equations[i][0]-'a',parent);
                int prntv = find(equations[i][3]-'a',parent);
                if (prntu != prntv)
                {
                    parent[prntv] = prntu;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if (equations[i][1] == '!') 
            {
                int prntu = find(equations[i][0]-'a',parent);
                int prntv = find(equations[i][3]-'a',parent);
                if (prntu == prntv)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
