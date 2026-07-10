class Solution {
public:
    bool isBalanced(string num) {
    int n=num.length();
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        nums[i]=num[i]-'0';
    }
    int sumeven=0;
    int sumodd=0;
    for(int i=0;i<n;i++){
        if(i%2==0) sumeven+=nums[i];
        else sumodd+=nums[i];
    }
    if(sumeven==sumodd) return true;
    return false;
    }
};