class Solution {
public:
 bool removeSenator(string &senate,char ch,int idx){
    bool checkRemovaleftside=false;
    while(true){
    if(idx==0)  checkRemovaleftside=true;
    if(senate[idx]==ch){
        senate.erase(begin(senate)+idx);
        break;
          }
          idx=(idx+1)%(senate.length());
     }
     return checkRemovaleftside;
 }
    string predictPartyVictory(string senate) {
        int Rcnt=0;
        int idx=0;
        int Dcnt=0;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R') Rcnt++;
            if(senate[i]=='D') Dcnt++;
        }
        int index=0;
        while(Rcnt>0 && Dcnt>0){
            if(senate[idx]=='R'){
            bool checkRemovaleftside=removeSenator(senate,'D',(idx+1)%(senate.length()));
            Dcnt--;
            if(checkRemovaleftside) idx--;
            }
            else{
            if(senate[idx]=='D'){
            bool checkRemovaleftside=removeSenator(senate,'R',(idx+1)%(senate.length()));
            Rcnt--;
            if(checkRemovaleftside) idx--;
            }
         
           }
           idx=(idx+1)%(senate.length());
        }
        if(Rcnt>0) return "Radiant";
        else return "Dire";
    }
};