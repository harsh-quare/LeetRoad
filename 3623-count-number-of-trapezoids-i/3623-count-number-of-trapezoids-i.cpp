class Solution {
public:
    const int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        for(auto& p: points){
            mp[p[1]]++;
        }

        long long ans = 0, sum = 0;
        for(auto& it : mp){
            int n = it.second;  // find nc2 => for each horizontal edge, number of ways
            long long edge = (long long)n * (n - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }

        return ans % mod;
    }
};

// for each y, we can select int mp[i]C2 ways.
//1. 3C2 * 2C2 => 3
//2. 2C2 * 2C2 => 1