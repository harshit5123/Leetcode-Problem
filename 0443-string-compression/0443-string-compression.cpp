class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int index=0;
        while(i<n){
            int curr_char=chars[i];
            int cnt=0;
            while(i<n && curr_char==chars[i]){
                cnt++;
                i++;
            }
            chars[index]=curr_char;
            index++;

            if(cnt>1){
            string strcnt=to_string(cnt);
            for(char& ch:strcnt){
                chars[index]=ch;
                index++;
               }
            }

        }
        return index;
    }
};