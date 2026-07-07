class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>copy=arr;
        sort(copy.begin(),copy.end());
        int rnk=1;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if (mpp.find(copy[i])==mpp.end()){
                mpp[copy[i]]=rnk;
                rnk++;
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(mpp[arr[i]]);
        }
       return res;

    }
};