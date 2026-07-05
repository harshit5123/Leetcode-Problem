class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int sum = 0;

        // Smallest and second smallest numbers
        // having remainder 1 and 2 respectively.
        int r1Min1 = INT_MAX, r1Min2 = INT_MAX;
        int r2Min1 = INT_MAX, r2Min2 = INT_MAX;

        for (int x : nums) {

            sum += x;

            if (x % 3 == 1) {

                // Maintain two smallest numbers
                if (x < r1Min1) {
                    r1Min2 = r1Min1;
                    r1Min1 = x;
                }
                else if (x < r1Min2) {
                    r1Min2 = x;
                }
            }

            else if (x % 3 == 2) {

                // Maintain two smallest numbers
                if (x < r2Min1) {
                    r2Min2 = r2Min1;
                    r2Min1 = x;
                }
                else if (x < r2Min2) {
                    r2Min2 = x;
                }
            }
        }

        // Already divisible by 3
        if (sum % 3 == 0)
            return sum;

        // Sum leaves remainder 1
        if (sum % 3 == 1) {

            int remove1 = r1Min1;                       // remove one remainder-1
            int remove2 = INT_MAX;

            // remove two remainder-2 numbers
            if (r2Min1 != INT_MAX && r2Min2 != INT_MAX)
                remove2 = r2Min1 + r2Min2;

            int remove = min(remove1, remove2);

            if (remove == INT_MAX)
                return 0;

            return sum - remove;
        }

        // Sum leaves remainder 2
        else {

            int remove1 = r2Min1;                       // remove one remainder-2
            int remove2 = INT_MAX;

            // remove two remainder-1 numbers
            if (r1Min1 != INT_MAX && r1Min2 != INT_MAX)
                remove2 = r1Min1 + r1Min2;

            int remove = min(remove1, remove2);

            if (remove == INT_MAX)
                return 0;

            return sum - remove;
        }
    }
};