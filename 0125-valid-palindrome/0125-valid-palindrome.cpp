class Solution {
public:
    bool isPal(int i, string& s){
        if(i >= s.size()/2) return true;

        if(s[i] != s[s.size()-i-1]) return false;

        return isPal(i+1, s);
    }
    bool isPalindrome(string s) {
        string modified;
        for(char c: s){
            if(isalnum(c)){
                modified += tolower(c);
            }
        }

        return isPal(0, modified);
    }
};