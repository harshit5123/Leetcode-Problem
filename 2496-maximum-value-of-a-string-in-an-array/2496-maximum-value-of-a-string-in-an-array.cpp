class Solution {
public:
    bool hasAlphabet(string s) {
        for (char c : s) {
            if (isalpha(c))
                return true;
        }
        return false;
    }

    int maximumValue(vector<string>& strs) {
        int ans = 0;

        for (string str : strs) {

            if (hasAlphabet(str)) {
                ans = max(ans, (int)str.size());
            }
            else {
                ans = max(ans, stoi(str));
            }
        }

        return ans;
    }
};