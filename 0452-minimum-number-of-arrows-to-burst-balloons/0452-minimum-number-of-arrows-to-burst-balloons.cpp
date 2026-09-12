class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            int currstartpoints = points[i][0];
            int currendpoints = points[i][1];
            int prevstartpoints = prev[0];
            int prevendpoints = prev[1];
            if (currstartpoints > prevendpoints) {
                // agar overlap nhi karenge..
                cnt++;
                prev = points[i];
            } else {
                // pakka overlap hoga
                prev[0] = max(prevstartpoints, currstartpoints);
                prev[1] = min(prevendpoints, currendpoints);
            }
        }
        return cnt;
    }
};