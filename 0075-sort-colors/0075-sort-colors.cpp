class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2)
                cnt2++;
            if (nums[i] == 1)
                cnt1++;
            if (nums[i] == 0)
                cnt0++;
        }
        int idx = 0;
        while (cnt0--)
            nums[idx++] = 0;
        while (cnt1--)
            nums[idx++] = 1;
        while (cnt2--)
            nums[idx++] = 2;
    }
};