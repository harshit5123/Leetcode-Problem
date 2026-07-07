class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>mpp;
        for(auto&task:tasks){
            mpp[task]++;
        }
        int round=0;
        for(auto&it:mpp){
            int cnt=it.second;
            if(cnt==1) return -1;
            if(cnt%3==0) round+=cnt/3;
            else round+=((cnt/3)+1);
        }
        return round;
    }
};