class Solution {
public:
    int maxProduct(int n) {
        int maxi=0;
        int smaxi=0;
        while(n>0){
            int lastdigit=n%10;
            if(lastdigit>=maxi){
                smaxi=maxi;
                maxi=lastdigit;
            }
            else if(lastdigit>smaxi){
                smaxi=lastdigit;
            }
            n=n/10;
        }
        return (maxi*smaxi);
    }
};