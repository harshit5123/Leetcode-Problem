class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        int n = rocks.size();
        vector<int> leftcap(n);
        for (int i = 0; i < n; i++) {
            leftcap[i] = capacity[i] - rocks[i];
        }
        sort(leftcap.begin(),leftcap.end());
        for (int& num : leftcap) {
            int take = min(num, additionalRocks);
            num -= take;
            additionalRocks -= take;

            if (additionalRocks == 0)
                break;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(leftcap[i]==0) ans++;
        }
        return ans;
    }
};