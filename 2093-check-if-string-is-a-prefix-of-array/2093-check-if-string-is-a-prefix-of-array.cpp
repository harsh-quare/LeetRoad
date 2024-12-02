class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string curr = "";
        for(string word : words) {
            curr += word;
            if(curr == s) return true;
        }

        return false;
    }
};