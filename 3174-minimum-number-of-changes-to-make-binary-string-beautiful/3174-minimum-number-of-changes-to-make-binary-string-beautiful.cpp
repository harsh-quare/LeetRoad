class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i+=2){
            //check every duo of length 2
            if(s[i] != s[i+1]) cnt++;
        }
        return cnt;
    }
};