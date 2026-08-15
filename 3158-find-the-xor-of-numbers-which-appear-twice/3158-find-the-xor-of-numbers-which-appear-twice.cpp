class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;

        for (int x : nums) {
            if (st.count(x)) {
                ans ^= x;
            } else {
                st.insert(x);
            }
        }

        return ans;
    }
};