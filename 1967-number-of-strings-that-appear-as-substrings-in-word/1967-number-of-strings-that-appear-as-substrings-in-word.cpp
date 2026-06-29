class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.length();
        unordered_set<string> st;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string res = "";
            for (int j = i; j < n; j++) {
                res += word[j];
                st.insert(res);
            }
        }
        int s = patterns.size();
        for (int i = 0; i < s; i++) {
            string s = patterns[i];
            if (st.find(s) != st.end())
                cnt++;
        }

        return cnt;
    }
};