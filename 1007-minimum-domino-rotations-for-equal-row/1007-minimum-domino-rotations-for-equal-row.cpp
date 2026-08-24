class Solution {
public:
    int possible(vector<int>&tops,vector<int>&bottoms,int &elem){
        int topswap=0;
        int bottomswap=0;
        int n=tops.size();
        for(int i=0;i<n;i++){
            if(tops[i]!=elem && bottoms[i]!=elem) return -1;
            if(tops[i]!=elem && bottoms[i]==elem) topswap++;
            if(tops[i]==elem && bottoms[i]!=elem) bottomswap++;
        }
    return min(topswap,bottomswap);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         int n = tops.size();
        int ans = INT_MAX;

        for(int i = 1; i <= 6; i++) {
            int curr = possible(tops, bottoms, i);

            if(curr != -1)
                ans = min(ans, curr);
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};