class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        if (source == target)
            return true;
        sort(source.begin(), source.end());
        sort(target.begin(), target.end());
        if (source == target)
            return true;
        long long sourcesum=0;
        long long targetsum=0;
        for(int i=0;i<n;i++){
            sourcesum+=source[i];
            targetsum+=target[i];
        }
        if(sourcesum==targetsum) return true;
        int j = n - 1;
        int delta = *max_element(target.begin(), target.end());
        for (int i = 0; i < n; i++) {
            long long ans = 1LL * source[i] + source[j] - delta;
            source[i] = (int)ans;
            source[j] = delta;
        }
        if (source == target )
            return true;
        return false;
    }
};