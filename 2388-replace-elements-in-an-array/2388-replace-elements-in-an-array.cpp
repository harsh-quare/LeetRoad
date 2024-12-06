class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }

        for(auto& it: operations){
            int a = it[0];
            int b = it[1];

            int idx = mp[a];
            nums[idx] = b;
            mp[b] = mp[a];
        }

        return nums;
    }
};