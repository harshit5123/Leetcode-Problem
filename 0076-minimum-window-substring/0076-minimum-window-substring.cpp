class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (n > m)
            return {};
        unordered_map<char, int> mp;
        // store karlia element ko
        for (char& ch : t) {
            mp[ch]++;
        }
        int requiredcnt = n;
        int i = 0, j = 0;
        int start = 0;
        int minwindow = INT_MAX;
        while (j < m) {
            char ch = s[j];
            if (mp[ch] > 0) {
                requiredcnt--;
            }
            mp[ch]--;
            while (requiredcnt == 0) {
                int currentwindow = j - i + 1;
                if (currentwindow < minwindow) {
                    minwindow = currentwindow;
                    start = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    requiredcnt++;
                }
                i++;
            }
            j++;
        }

        if (minwindow == INT_MAX)
            return "";

        return s.substr(start, minwindow);
    }
};