class Solution {
public:
    void solve(int val, int n, vector<int>& ans){
        if(val > n) return ;

        if(val <= n) ans.push_back(val);

        for(int dig = 0; dig <= 9; dig++){
            solve(val*10 + dig, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // hame sbse pahle saare 1 digit se start hone wale numbers chahiye, fir 2 digit se start hone wale, and so on
        for(int i = 1; i <= 9; i++){  // try for all leftmost digits possible
            solve(i, n, ans);
        }

        return ans;
    }
};