class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        if(s[0] != words[0][0] || s.size() < words[0].size()) return false;

        string temp = "";
        for(int i = 0; i < words.size(); i++){
            temp += words[i];
            if(temp == s) return true;
            if(temp.length() > s.length()) return false;
        }

        return false;
    }
};