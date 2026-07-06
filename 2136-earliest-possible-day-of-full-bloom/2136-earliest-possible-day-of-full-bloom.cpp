class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=growTime.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        auto lambda=[](pair<int,int>&P1,pair<int,int>&P2){
            return P1.second>P2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        int maxbloomdays=0;
        int prevMax=0;
        for(int i=0;i<n;i++){
           int currplantdays=vec[i].first;
           int growth=vec[i].second;
           prevMax+=currplantdays;
           int bloomday=prevMax+growth;
           maxbloomdays=max(maxbloomdays,bloomday);
        }
        return maxbloomdays;
    }
};