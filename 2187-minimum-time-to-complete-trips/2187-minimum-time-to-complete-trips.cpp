class Solution {
public:
    bool  possibletripTime(vector<int>& time, long long giventime,int totalTrips) {
    long long actualtrips = 0;

    for (int &t: time) {
        actualtrips+=giventime/t;
        }

    return actualtrips>=totalTrips;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
      int  n=time.size();
      long long low=1;
      long long high=(long long)*min_element(begin(time),end(time))*totalTrips;
      while(low<high){
        long long mid=(low)+(high-low)/2;
        if(possibletripTime(time,mid,totalTrips)) high=mid;
        else low=mid+1;
      }
      return low;  
    }
};