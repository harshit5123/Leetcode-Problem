class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        int cntf=0;
        int cntt=0;
        int i=0;
        int maxi=0;
        for(int j=0;j<n;j++){
            if(answerKey[j]=='F') cntf++;
            while(cntf>k){
                if(answerKey[i]=='F') cntf--;
                i++;
            }
            maxi=max(maxi,j-i+1);
        }
        i=0;
        for(int j=0;j<n;j++){
            if(answerKey[j]=='T') cntt++;
            while(cntt>k){
                if(answerKey[i]=='T') cntt--;
                i++;
            }
            maxi=max(maxi,j-i+1);
        }

        return maxi;
    }
};