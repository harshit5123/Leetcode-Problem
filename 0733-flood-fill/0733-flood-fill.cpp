class Solution {
private: 
    void dfs(vector<vector<int>>&image,int row ,int col ,vector<vector<int>>&ans,int color,int delRow[],int delCol[],int intialcolor){
      int n=image.size();
      int m=image[0].size();
      ans[row][col]=color;
      for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==intialcolor && ans[nrow][ncol]!=color){
           dfs(image,nrow,ncol,ans,color,delRow,delCol,intialcolor);
        }
      }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans=image;
        int intialcolor=image[sr][sc];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        dfs(image,sr,sc,ans,color,delRow,delCol,intialcolor);
        return ans;
    }
};