class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        int N=restrictions.size();
        for(int i=1;i<N;i++){
            int diffdis=restrictions[i][0]-restrictions[i-1][0];
            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+diffdis);
        }
        for(int i=N-2;i>=0;i--){
            int diffdis=restrictions[i+1][0]-restrictions[i][0];
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+diffdis);
        }
        int result=0;
        for(int i=1;i<N;i++){
            int leftpos=restrictions[i-1][0];
            int leftheight=restrictions[i-1][1];
            int currpos=restrictions[i][0];
            int currheight=restrictions[i][1];
            int d= currpos-leftpos;
            int htdiff=abs(leftheight-currheight);
            int peak=max(leftheight,currheight)+(d-htdiff)/2;
            result=max(result,peak);

        }
        return result;
    }
};