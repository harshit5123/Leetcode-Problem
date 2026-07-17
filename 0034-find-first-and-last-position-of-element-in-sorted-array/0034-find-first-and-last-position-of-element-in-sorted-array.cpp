class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int leftindex = -1;
        int rightindex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                leftindex = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (leftindex == -1)
            return {-1, -1};
        int index =
            upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        rightindex = index-1;
        return {leftindex, rightindex};
    }
};