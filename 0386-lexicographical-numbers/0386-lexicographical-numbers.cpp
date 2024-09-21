class Solution {
public:
    void solve(int val, int n, vector<int>& ans){
        if(val > n) return ;

        if(val <= n) ans.push_back(val);
        for(int i = 0; i < 10; i++){
            solve(val*10 + i, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i < 10; i++){
            solve(i, n, ans);
        }
        return ans;
    }
};