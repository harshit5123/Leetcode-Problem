class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    int n=tokens.size();
    int i=0;
    int j=n-1;
    int maxscore=0;
    int score=0;
    sort(tokens.begin(),tokens.end());
    while(i<=j){
        if(power>=tokens[i]){
           score++;
           power-=tokens[i];
           i++;
        }
        else if(score>=1){
                score--;
                power+=tokens[j];
                j--;
            }
        
        else{
            break;
        }
        maxscore=max(maxscore,score);
        
    }
    return maxscore;
    }
};