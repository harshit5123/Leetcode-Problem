class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int onecnt = 0;
        int flips = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                onecnt++;

            else flips = min(flips + 1, onecnt);
        }
        return flips;
    }
};