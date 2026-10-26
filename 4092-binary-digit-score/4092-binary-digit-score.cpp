class Solution {
    public:
    int cntsetbit(int num){
        int cnt=0;
        while(num>0){
          int bit=num%2;
          cnt+=bit;
          num=num/2;
        }
        return cnt;
    }
public:
    int calculateScore(int a, int b) {
       int n1=cntsetbit(a);
       int n2=cntsetbit(b);
       if(n1>=n2) return n1*n2;
       return n2/n1;
    }
};