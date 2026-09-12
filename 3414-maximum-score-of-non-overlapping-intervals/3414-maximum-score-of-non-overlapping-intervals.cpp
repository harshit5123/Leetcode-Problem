class Solution {
public:
    struct State {
        long long score = 0;
        array<int, 4> ids{};
        int cnt = 0;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        for (int i = 0; i < a.cnt; i++) {
            if (a.ids[i] != b.ids[i])
                return a.ids[i] < b.ids[i];
        }

        return a.cnt < b.cnt;
    }

    void addID(State& s, int id) {
        int pos = s.cnt;

        while (pos > 0 && s.ids[pos - 1] > id) {
            s.ids[pos] = s.ids[pos - 1];
            pos--;
        }

        s.ids[pos] = id;
        s.cnt++;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [start, end, weight, original index]
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by ending time.
        sort(a.begin(), a.end(),
            [](const auto& x, const auto& y) {
                if (x[1] != y[1])
                    return x[1] < y[1];

                return x[0] < y[0];
            });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        // prev[i] = first index after all intervals
        // whose end < current interval's start.
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(
                    ends.begin(),
                    ends.begin() + i,
                    a[i][0]
                ) - ends.begin();
        }

        /*
            dp[k][i] =
            best answer using first i intervals
            with at most k intervals.
        */

        vector<State> dp[5];

        for (int k = 0; k <= 4; k++)
            dp[k].resize(n + 1);

        for (int i = 1; i <= n; i++) {

            int x = i - 1;

            for (int k = 1; k <= 4; k++) {

                // Don't take current interval.
                dp[k][i] = dp[k][i - 1];

                // Take current interval.
                State take = dp[k - 1][prev[x]];

                take.score += a[x][2];

                addID(take, (int)a[x][3]);

                if (better(take, dp[k][i]))
                    dp[k][i] = take;
            }
        }

        State ans;

        for (int k = 1; k <= 4; k++) {
            if (better(dp[k][n], ans))
                ans = dp[k][n];
        }

        vector<int> result;

        for (int i = 0; i < ans.cnt; i++)
            result.push_back(ans.ids[i]);

        return result;
    }
};