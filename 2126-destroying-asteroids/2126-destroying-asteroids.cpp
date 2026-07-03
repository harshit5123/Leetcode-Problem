class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long Mass=mass;
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<n;i++){
            if(Mass>=asteroids[i]){
                Mass+=asteroids[i];
            }
            else {
                return false;
            }
        }
        return true;
    }
};