class Solution {
public:
    bool checkzero(vector<int>&lower){
        for(int &i:lower){
            if(i!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        int t=s.size();
        vector<int> ans;
        vector<int>lower(26,0);
        for(int i=0;i<n;i++){
            char ch=p[i];
            lower[ch-'a']++;
        }
        int i=0;
        int j=0;
        while(j<t){
            lower[s[j]-'a']--;
            if(j-i+1==n){
                if(checkzero(lower)){
                    ans.push_back(i);
                    
                }
                lower[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};