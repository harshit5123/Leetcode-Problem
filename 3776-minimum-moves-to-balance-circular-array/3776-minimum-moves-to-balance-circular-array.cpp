class Solution {
public:
    typedef long long ll ;
    ll minMoves(vector<int>& balance) {
        int n = balance.size();
        ll sum = 0;
        int culpritindex = -1;
        for (long long i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0)
                culpritindex = i;
        }
        if (culpritindex == -1)
            return 0;
        if (sum < 0)
            return -1;
        ll moves = 0;
        int dist = 1;
        while (balance[culpritindex] < 0) {
            int left = (culpritindex - dist + n) % n;
            int right = (culpritindex +dist) % n;
            ll available = balance[left] + balance[right];
            if (left == right)
                available -= balance[left];
            ll needed = -balance[culpritindex];
            ll taken = min(needed, available);
            moves += dist * taken;
            balance[culpritindex] += taken;
            dist++;
        }
        return moves;
    }
};