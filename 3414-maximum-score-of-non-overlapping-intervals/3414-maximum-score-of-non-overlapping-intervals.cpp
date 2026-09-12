class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    // Return true if a is lexicographically smaller than b.
    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(a.ids.begin(), a.ids.end(),
                                       b.ids.begin(), b.ids.end());
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [left, right, weight, original_index]
        vector<array<long long, 4>> a;
        a.reserve(n);

        for (int i = 0; i < n; ++i) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        // Sort by ending position.
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // ends[i] = right endpoint of interval i.
        vector<long long> ends(n);
        for (int i = 0; i < n; ++i)
            ends[i] = a[i][1];

        // prev[i] = number of intervals among [0, i)
        // whose right endpoint is strictly smaller than a[i].left.
        //
        // Thus prev[i] is also the DP prefix index we can transition from.
        vector<int> prev(n);

        for (int i = 0; i < n; ++i) {
            prev[i] = lower_bound(ends.begin(), ends.begin() + i, a[i][0]) -
                      ends.begin();
        }

        // dp[k][i]:
        // best answer using the first i intervals, choosing at most k.
        //
        // We only need two rows because transitions use k-1.
        vector<State> dp[5], ndp[5];

        for (int k = 0; k <= 4; ++k) {
            dp[k].resize(n + 1);
            ndp[k].resize(n + 1);
        }

        for (int i = 1; i <= n; ++i) {
            int x = i - 1;

            for (int k = 0; k <= 4; ++k) {
                // Don't take interval x.
                ndp[k][i] = dp[k][i - 1];

                if (k > 0) {
                    // Take interval x.
                    State take = dp[k - 1][prev[x]];

                    take.score += a[x][2];
                    take.ids.push_back((int)a[x][3]);

                    sort(take.ids.begin(), take.ids.end());

                    if (better(take, ndp[k][i]))
                        ndp[k][i] = move(take);
                }
            }

            for (int k = 0; k <= 4; ++k)
                dp[k][i] = ndp[k][i];
        }

        State ans = dp[0][n];

        for (int k = 1; k <= 4; ++k) {
            if (better(dp[k][n], ans))
                ans = dp[k][n];
        }

        return ans.ids;
    }
};