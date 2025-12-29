class Solution {
public:
    bool solve(string bottom, unordered_map<string, vector<char>>& mp, int id, string top, unordered_map<string, bool>& dp){
        if(bottom.size() == 1) return true;


        string encodedKey = bottom + "." + to_string(id) + "." + top;
        if(dp.count(encodedKey)) return dp[encodedKey];



        if(id == bottom.size()-1) return dp[encodedKey] = solve(top, mp, 0, "", dp);  // start processing next string from scratch

        string curSubstr = bottom.substr(id, 2);
        if(mp.find(curSubstr) == mp.end()) return dp[encodedKey] = false;

        //backtracking
        for(auto& topChar: mp[curSubstr]){
            top.push_back(topChar);   // try

            if(solve(bottom, mp, id+1, top, dp) == true) return dp[encodedKey] = true;  // explore

            top.pop_back();  // undo
        }

        return dp[encodedKey] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(auto& str: allowed){
            mp[str.substr(0, 2)].push_back(str[2]);
        }

        unordered_map<string, bool> dp;

        return solve(bottom, mp, 0, "", dp);  // currBottom, mp, idx, aboveLayer
    }
};