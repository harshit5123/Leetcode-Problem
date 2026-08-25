class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m=banned.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[banned[i]]=1;
        }
        for(auto it:mpp){
            cout<< it.second <<" ";
        }
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
              if(mpp.find(i)!=mpp.end()) continue;
              if(sum+i>maxSum){
                 break;
              }
              sum+=i;
              ans++;
        }
    return ans;    
    }
};