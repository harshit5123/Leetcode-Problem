class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int> hash(128, 0);

for (char ch : s) {
    hash[ch]++;
}

int ans = 0;
bool odd = false;

for (int i = 0; i < 128; i++) {
    if (hash[i] % 2 == 0) {
        ans += hash[i];
    } else {
        ans += hash[i] - 1;
        odd = true;
    }
}
//if any odd character left(agar koi bacha hai to)
if (odd)
    ans++;       // Place one odd character in the center of palindrome

return ans;
    }
};