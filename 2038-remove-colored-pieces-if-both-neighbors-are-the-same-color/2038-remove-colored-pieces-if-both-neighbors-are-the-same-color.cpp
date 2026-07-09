class Solution {
public:
    bool winnerOfGame(string colors) {
        int s=colors.length();
        int i=0;
        int cntA=0;
        int cntB=0;
        int moves=0;
        int moves2=0;
        while(i<s){
            while(colors[i]=='A'){
                cntA++;
                i++;

            }
            if(cntA>2) moves+=cntA-2;
            cntA=0;
            while(colors[i]=='B') {
                
                cntB++;
                i++;
            }
            if(cntB>2) moves2+=cntB-2;
            cntB=0;
        }
        if(moves>moves2) return true;
        return false;
    }
};