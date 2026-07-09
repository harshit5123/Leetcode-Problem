class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> lower(26, 0);
        for (int i = 0; i < n; i++) {
            lower[s[i] - 'a']++;
        }
        int cnt = 0;
        unordered_set<int> st;
        for (int i = 0; i < 26; i++) {
            while(lower[i]>0 && st.find(lower[i])!=st.end()) {
                lower[i] -= 1;
                cnt++;
           }
        st.insert(lower[i]);
        }
        return cnt;
    }
};