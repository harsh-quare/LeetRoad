class Solution {
public:
    const int mod = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int> dp(n+1), pref(n+1);
        dp[0] = pref[0] = 1;

        multiset<int> ms;
        int left = 0;

        for(int i = 1; i <= n; i++){
            ms.insert(nums[i-1]);

            while(*(ms.rbegin()) - *(ms.begin()) > k){
                ms.erase(ms.find(nums[left]));
                left++;
            }

            dp[i] = (pref[i-1] - ((left - 1 >= 0) ? pref[left-1] : 0) + mod) % mod;
            pref[i] = (pref[i-1] + dp[i]) % mod;
        }

        return dp[n];
    }
};