class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Sort by length
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;

        int ans = 1;

        for (string &word : words) {
            int best = 1;

            // Try removing each character
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);

                // If predecessor exists
                if (dp.find(prev) != dp.end()) {
                    best = max(best, dp[prev] + 1);
                }
            }

            dp[word] = best;
            ans = max(ans, best);
        }

        return ans;
    }
};