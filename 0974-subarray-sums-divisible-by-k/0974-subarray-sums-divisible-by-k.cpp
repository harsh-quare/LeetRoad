class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;  // 0-sum
        int pref = 0;
        for(int i = 0; i < n; i++){
            pref = (pref + nums[i]) % k;

            pref = (pref + k) % k;
            cnt += mp[pref];

            mp[pref]++;
        }

        return cnt;
    }
};