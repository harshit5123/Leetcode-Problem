class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>copy=nums;
        set<int> ans;
        sort(copy.begin(),copy.end());
        int i=0;
        int j=copy.size()-1;
        int n1=copy[i],n2=copy[j];
        while(i<j){
            if(copy[i]+copy[j]==target) {
                n1=copy[i];
                n2=copy[j];
                break;
            }
            else if(copy[i]+copy[j]<target){
               i++;
            }
            else{
                j--;
            }
        }

        if (n1+n2!=target) return {-1,-1};
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1) ans.insert(i);
            if(nums[i]==n2) ans.insert(i);
        }

        vector<int>res;
        for (auto el:ans){
            res.push_back(el);
        }
        return res;
    }
};