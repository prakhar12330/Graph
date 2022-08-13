class Solution {
public:
    int FindParent(int x,vector<int>&parent)
    {
        //When Element Is Self Leader
        if(parent[x]==-1) return x; 
        
        return parent[x]=FindParent(parent[x],parent);
    }
    void doUnion(int a,int b, vector<int>&parent)
    {
        //Finding parent of both a and b
        int prnta=FindParent(a,parent);
        int prntb=FindParent(b,parent);
        
        //If Parent for both of them are same then simply return
        if(prnta==prntb) return; 
        // if both of them are from have different parent then union them and make a single common group
        parent[prnta]=prntb;
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        vector<int>parent(n,-1);//For Storing The Parent Of Every Node,Initially every node's parent is -1
        
        //Making group of the cities which are connected
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    doUnion(i,j,parent);
                }
            }
        }
        int count=0; 
        
        //counting groups
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1) count++; 
        }
        return count; 
        
    }
};
