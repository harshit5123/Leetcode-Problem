class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size()-1;
        vector<int> ans;
        int carry=0;
        while(n>=0 || k>0){
            int sum=0;
            if(k>0){
            int lastdigit=k%10;
            sum+=lastdigit;
            k=k/10;
            }
            if(n>=0){
                int nums=num[n];
                sum+=nums;
                n--;
            }
            sum+=carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit);
            
        }
        if(carry>0) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};