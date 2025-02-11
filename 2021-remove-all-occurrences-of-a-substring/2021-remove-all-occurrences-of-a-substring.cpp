class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        string ans = "";

        for(char c: s){
            ans += c;

            if(ans.back() == part[n-1]){
                if(ans.size() >= n && ans.substr(ans.size() - n) == part){
                    ans.erase(ans.size()- n);
                }
            }
        }

        return ans;
    }
};