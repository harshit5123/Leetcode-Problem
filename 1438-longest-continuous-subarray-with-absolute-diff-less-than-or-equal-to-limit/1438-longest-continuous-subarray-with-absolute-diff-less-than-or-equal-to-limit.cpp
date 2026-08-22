class Solution {
public:
    typedef pair<int,int>P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int> st;
        int l=0;
        int r=0;
        int maxi=0;
        while(r<n){
            st.insert(nums[r]);
            if(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[l]));
                l++;
            }
            maxi=max(maxi,(r-l)+1);
            r++;
        }
       /* priority_queue< P,vector<P>> maxq;
        priority_queue<P,vector<P>,greater<P>> minq;
        int i=0;
        int j=0;
        int n=nums.size();
        int maxi=0;
        int maxlen=0;
        while(j<n){
            maxq.push({nums[j],j});
            minq.push({nums[j],j});
            while(maxq.top().first-minq.top().first>limit){
                i=min(maxq.top().second,minq.top().second)+1;
                while(maxq.top().second<i) maxq.pop();
                while(minq.top().second<i) minq.pop();
            }
        maxi=max(maxi,(j-i)+1);
        j++;
        }. */
        return maxi;
    }
};