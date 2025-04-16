class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;

        long long pairs = 0;
        long long ans = 0;

        unordered_map<int, int> mp;

        while(r < n){
            pairs += mp[nums[r]];   // abhi tk kitni baar same element mil chuka h
            mp[nums[r]]++;

            while(pairs >= k){
                ans += (n - r);  // agar current 'r' pe pairs >= k ho gye h, to isse aage saare elements ko one by one leke jo bi subarrs banange, woh bhi good subarrs hi honge
                mp[nums[l]]--;  // strink window, remove the freq of left pointer
                pairs -= mp[nums[l]];  // pair count bhi reduce kr do
                l++;
            }
            r++;
        }

        return ans;
    }
};