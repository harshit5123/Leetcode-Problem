class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>mpp;
        for(auto&word:words){
            mpp[word]++;
        }
        
        bool center=false ;// center hai ye . sirf ek hi element center pe used  kar sakte hai isliye
        int result=0;
        for(auto & word:words){
            string res=word;
            reverse(res.begin(),res.end());
            if(res!=word){
                if(mpp[word]>0 && mpp[res]>0){
                    mpp[word]--;
                    mpp[res]--;
                    result+=4;
                }
            }
            else{
                if(mpp[word]>=2){
                    mpp[word]-=2;
                    result+=4;
                }
                else if(mpp[word]==1 && center==false){
                    mpp[word]--;
                    result+=2;
                    center=true;
                }
              }
            
        }
        return result;
    }
};