class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=growTime.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        auto lambda=[](pair<int,int>&P2,pair<int,int>&P1){
            return P2.second>P1.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        for(int i=0;i<n;i++){
            cout<<vec[i].first<<" "<<vec[i].second<<"\n";
        }
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