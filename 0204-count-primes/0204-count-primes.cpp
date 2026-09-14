class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int count = 1; // account for 2, the only even prime
        int size = (n + 1) / 2; // isComposite[k] represents odd number (2k+1)
        vector<char> isComposite(size, 0);

        for (int i = 3; (long long)i * i < n; i += 2) {
            if (!isComposite[i >> 1]) {
                for (long long j = (long long)i * i; j < n; j += 2 * i) {
                    isComposite[j >> 1] = 1;
                }
            }
        }

        for (int k = 1; 2 * k + 1 < n; k++) {
            if (!isComposite[k]) count++;
        }
        return count;
    }
};