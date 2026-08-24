class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftsum=0;
        int rightsum=0;
        int leftqs=0;
        int rightqs=0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    leftqs++;
                else
                    rightqs++;
            } else {
                if (i < n / 2)
                    leftsum += num[i]-'0';
                else
                    rightsum += num[i]-'0';
            }
        }
        if ((leftqs + rightqs) % 2 == 1)
            return true;
        int left = 2 * leftsum + 9 * leftqs;
        int right = 2 * rightsum + 9 * rightqs;
        if (left == right) {
            return false;
        }
        return true;
    }
};