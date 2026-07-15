class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        set<int> st;

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (j - i > k) {
                st.erase(nums[i]);
                i++;
            }

            if (st.find(nums[j]) != st.end())
                return true;

            st.insert(nums[j]);
        }

        return false;
    }
};