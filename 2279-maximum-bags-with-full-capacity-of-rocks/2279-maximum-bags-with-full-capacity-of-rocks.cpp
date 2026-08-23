class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int m=rocks.size();
        int ans=0;
        for(int i=0;i<n;i++){
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<n;i++){
            if(capacity[i]<=additionalRocks) {
                additionalRocks-=capacity[i];
                ans+=1;
            }
            else{
                break;
            }
       }
    return ans;
    }
};