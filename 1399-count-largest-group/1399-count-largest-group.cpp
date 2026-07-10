class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        for(int i=1;i<=n;i++){
            int num=i;
            int sum=0;
            while(num>0){
                int lastdigit=num%10;
                sum+=lastdigit;
                num=num/10;
            }
            mpp[sum]+=1;
        }
        int maxi=0;
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        int ans=0;
        for(auto it:mpp){
            if(maxi==it.second) ans++;
        }
        return ans;
    }
};