class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        int i = 0;
        string ans = "";

        while(i < s.size()){
            ans += s[i];

            if(ans.back() == part[n-1]){
                if(ans.size() >= n && ans.substr(ans.size() - n, n) == part){
                    for(int k = 0; k < n; k++){
                        ans.pop_back();
                    }
                }
            }

            i++;
        }

        return ans;
    }
};