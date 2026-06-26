class Solution {
public:
     # define  ll long long 
    bool isvowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    long long beautifulSubstrings(string s, int k) {
        ll vowel=0;
        ll consonant=0;
        ll result=0;
        unordered_map<ll,unordered_map<ll,ll>>mp;
        mp[0][0]=1;
        for(char &ch:s){
            if(isvowel(ch))vowel++;
            else consonant++;
            ll prefixsum=vowel-consonant;
            for(auto &[pastVowelcnt,count]:mp[prefixsum]){
                if((vowel%k-pastVowelcnt)*(vowel%k-pastVowelcnt)%k==0) result+=count;
            } 
            mp[prefixsum][vowel%k]++;
        }
        return result;
    }
};