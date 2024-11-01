class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int cnt = 0;
        for(auto c : s){
            cnt++;
            if(!ans.empty() && ans.back() != c) cnt = 1;
            if(cnt < 3) ans.push_back(c);
        }
        return ans;
    }
};