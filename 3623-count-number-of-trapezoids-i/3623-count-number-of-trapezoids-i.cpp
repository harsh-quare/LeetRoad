class Solution {
public:
    long long findncr(int n){
        // nc2 => n*(n-1) / 2;
        return (long long)n * (n-1) / 2;
    }
    const int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        for(auto& p: points){
            mp[p[1]]++;
        }

        long long sum = 0, sq = 0;
        for (auto& it : mp) {
            long long x = findncr(it.second);  // r = 2 always in our case
            sum = (sum + x) % mod;
            sq  = (sq + (x * x) % mod) % mod;
        }

        long long sum_sq = (sum * sum) % mod;
        long long diff = (sum_sq - sq + mod) % mod;

        long long inv2 = (mod + 1) / 2;   // modular inverse of 2 under mod 1e9+7

        long long ans = (diff * inv2) % mod;
        return ans;
    }
};

// for each y, we can select int mp[i]C2 ways.
//1. 3C2 * 2C2 => 3
//2. 2C2 * 2C2 => 1