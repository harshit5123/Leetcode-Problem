class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        vector<int> pairs;
        int cnt =0;
        string s="";
        for(int i=0;i<n;i++){
            s+=to_string(nums[i]);
            cnt++;
            if(cnt==2){
                cnt=0;
                pairs.push_back(stoi(s));
                s.clear();
            }
            
        }
        for(auto it:pairs){
            cout << it << endl;
        }
        sort(pairs.begin(),pairs.end());
        return pairs[0];

    }
};