class Solution {
public:
    // by using diffrence array logic to check whether the soln exists or not..
    // use kadane algo to find the starting index of the gas station..
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgain = accumulate(gas.begin(), gas.end(),0);
        int totalloss = accumulate(cost.begin(), cost.end(),0);
        if (totalloss > totalgain)
            return -1;
        int total_sum = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            total_sum += gas[i] - cost[i];
            if (total_sum < 0) {
                total_sum = 0;
                index = i + 1;
            }
        }
        return index;
    }
};