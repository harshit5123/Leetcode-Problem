class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int res = 0;

        for (int i = 0; i < n; i++) {
            string ans="";
            int vowels = 0;
            int consonants = 0;
            for (int j=i;j<n;j++){
                ans+=s[j];
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||s[j]== 'u') vowels++;
                else consonants++;
                if (vowels == consonants && (vowels * consonants) % k == 0) res++;
            }
        }
        return res;
    }
};