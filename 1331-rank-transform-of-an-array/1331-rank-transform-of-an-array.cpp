class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        unordered_map<int,int>mpp;
        vector<int>res;
        int rnk=1;
        for(int i=0;i<n;i++){
           if(mpp.find(copy[i])==mpp.end()){
              mpp[copy[i]]=rnk;
              rnk++;
           }
        }
        for(int i=0;i<n;i++){
            res.push_back(mpp[arr[i]]);
        }
        return res;
    }
};