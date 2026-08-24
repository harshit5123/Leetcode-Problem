class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        long long sum1=0;
        int zerocnt1=0;
        for(int i=0;i<n1;i++){
            sum1+=nums1[i]*1ll;
            if(nums1[i]==0) zerocnt1++;
        }
        long long sum2=0;
        int zerocnt2=0;
        for(int i=0;i<n2;i++){
            sum2+=nums2[i]*1ll;
            if(nums2[i]==0) zerocnt2++;
        }
        long long minscore1=sum1+zerocnt1;
        long long minscore2=sum2+zerocnt2;
        if(minscore1>minscore2 && zerocnt2==0) return -1;
        if(minscore2>minscore1 && zerocnt1==0) return -1;
        long long ans=max(minscore1,minscore2);
        return ans;
    }
};