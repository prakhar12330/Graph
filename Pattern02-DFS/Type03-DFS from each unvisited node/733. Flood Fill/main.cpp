class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,int m,int n,int newColor,int color)
    {
        if(row<0||col<0||row>=m||col>=n||image[row][col]!= color)return;
        
        image[row][col]=newColor;
        dfs(image,row+1,col,m,n,newColor,color);
        dfs(image,row-1,col,m,n,newColor,color);
        dfs(image,row,col-1,m,n,newColor,color);
        dfs(image,row,col+1,m,n,newColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int m=image.size();
        int n=image[0].size();
        
        int color=image[sr][sc];
        if(color == newColor)
        {
         return image;
        }
        
        dfs(image,sr,sc,m,n,newColor,color);
        
        return image;
        
    }
};
