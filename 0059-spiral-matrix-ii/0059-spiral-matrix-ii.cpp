class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num=1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans[top][i]=num;
                num++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans[i][right]=num;
                num++;
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i]=num;
                    num++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left]=num;
                    num++;
                }
                left++;
            }
        }
        return ans;
    }
};