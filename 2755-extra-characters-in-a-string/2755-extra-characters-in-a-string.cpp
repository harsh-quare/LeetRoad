class Solution {
public:
    int solve(int i, string s, int n, unordered_set<string>& st, vector<int>& dp){
        if(i >= n) return 0;  //no character is left out and we are out of bound

        if(dp[i] != -1) return dp[i];
        
        int res = INT_MAX;

        //Take current character as left out character, means skip it and solve for remaining string, ans also count it as 1 because this is left out
        int take = 1 + solve(i+1, s, n, st, dp);
        res = min(res, take);

        //Include current character in your string that you are trying to find in dict, means try to create that substring
        for(int j = i; j < n; j++){
            string sub = s.substr(i, j-i+1);
            if(st.count(sub)){
                res = min(res, solve(j+1, s, n, st, dp));
            }
        }

        return dp[i] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        vector<int> dp(n, -1);

        return solve(0, s, n, st, dp);
    }
};