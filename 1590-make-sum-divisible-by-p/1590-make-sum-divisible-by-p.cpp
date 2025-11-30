class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for(int x: nums) total += x;

        cout << total << endl;

        if(total % p == 0) return 0;
        if(total < p) return -1;

        int subArrSum = total % p;

        int mini = n;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int pref = 0;
        for(int i = 0; i < n; i++){
            pref = (pref + nums[i]) % p;

            int reqd = (pref - subArrSum + p) % p;

            if(mp.find(reqd) != mp.end()){
                mini = min(mini, i - mp[reqd]);
            }

            mp[pref] = i;
        }

        return mini == n ? -1 : mini;
    }
};