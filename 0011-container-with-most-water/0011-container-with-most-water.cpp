class Solution {
public:
    long long  maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxi=0;
        while(i<j){
            int minheight=min(height[i],height[j]);
            int area=minheight*(j-i);
            maxi=max(maxi,area);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxi;
    }
};