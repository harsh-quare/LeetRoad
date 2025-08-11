class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> v;
        long long val = 1, mod = 1e9 + 7;
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)) v.push_back(val);
            val *= 2;
            val %= mod;
        }

        // for(int i = 1; i < v.size(); i++){
        //     v[i] *= v[i-1];
        // }

        vector<int> ans;
        for(auto &it: queries){
            long long curr = 1;
            for(int i = it[0]; i <= it[1]; i++){
                curr *= v[i];
                curr %= mod;
            }
            ans.push_back(curr);

        }
        return ans;
    }
};