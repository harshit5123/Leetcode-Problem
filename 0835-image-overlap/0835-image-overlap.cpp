class Solution {
public:
    int countOverlaps(vector<vector<int>>&img1,vector<vector<int>>&img2,int rowoffset,int coloffset){
        //A[i][j]=B[i+rowoffset][j+coloffset]
        int n=img1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int img2i=i+rowoffset;
                int img2j=j+coloffset;
                if(img2i<0 || img2i>=n || img2j<0 || img2j>=n) continue;
                if(img1[i][j]==1 && img2[img2i][img2j]==1) count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxi=0;
        //n*m matrix
        //i=row_offset
        //j=col_offset
        for(int rowoffset=-n+1;rowoffset<n;rowoffset++){
            for(int coloffset=-n+1;coloffset<n;coloffset++){
                int count=countOverlaps(img1,img2,rowoffset,coloffset);
                maxi=max(maxi,count);

            }
        }
        return maxi;
    }
};