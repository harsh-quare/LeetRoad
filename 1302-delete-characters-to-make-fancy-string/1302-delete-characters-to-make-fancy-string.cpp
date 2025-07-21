class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        
        string ans;
        ans.push_back(s[0]);
        for(int i = 1; i < n; i++){
            //check if cur character, next character and the character last pushed into ans are same
            if(i+1 < n && ans.back() == s[i] && s[i] == s[i+1]){
                continue;   // current character ko skip kr do
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};