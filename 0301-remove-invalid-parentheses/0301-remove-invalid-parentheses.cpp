class Solution {
public:
    unordered_set<string> ans;

    void solve(string s, int index, int leftRemove, int rightRemove) {
        if (leftRemove == 0 && rightRemove == 0) {
            int balance = 0;

            for (char c : s) {
                if (c == '(')
                    balance++;
                else if (c == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.insert(s);

            return;
        }

        for (int i = index; i < s.size(); i++) {

            // Avoid generating duplicate strings
            if (i > index && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (leftRemove > 0 && s[i] == '(') {
                string next = s.substr(0, i) + s.substr(i + 1);
                solve(next, i, leftRemove - 1, rightRemove);
            }

            // Remove ')'
            if (rightRemove > 0 && s[i] == ')') {
                string next = s.substr(0, i) + s.substr(i + 1);
                solve(next, i, leftRemove, rightRemove - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of removals
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        solve(s, 0, leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};