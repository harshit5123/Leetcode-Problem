class Solution {
public:
    int brokenCalc(int startValue, int target) {
    long long minsteps=0;
    while(true){
        if (target==startValue) break;

        if (target%2==0){
            if (startValue>target) target+=1;
            else target=target/2;
        }
        else target+=1;
        minsteps++;
    }
    return minsteps;
    }
};