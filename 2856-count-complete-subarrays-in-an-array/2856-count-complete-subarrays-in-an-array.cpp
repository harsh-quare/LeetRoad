class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int distArr = mp.size();
        mp.clear();
        int ans = 0;

        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;

            while(mp.size() == distArr){
                ans += n - j;  // all remaining will also satisfy the condition
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return ans;
    }
};