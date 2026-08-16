class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> freq(100001, 0);

        for (int x : nums) {
            if (x % 2 == 0) {
                freq[x]++;
            }
        }

        int ans = -1;
        int maxi = 0;

        for (int x = 0; x <= 100000; x += 2) {
            if (freq[x] > maxi) {
                maxi = freq[x];
                ans = x;
            }
        }

        return ans;
    }
};