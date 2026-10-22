
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = 0;

        while (nums[p] != 0) {
            p++;
        }

        bool normal = true, reversed = true;

        for (int i = 0; i < n; i++) {
            if (nums[(p + i) % n] != i)
                normal = false;

            if (nums[(p - i + n) % n] != i)
                reversed = false;
        }

        if (!normal && !reversed)
            return -1;

        if (normal)
            return min(p, n - p + 2);

        return min(p + 2, n - p);
    }
};
