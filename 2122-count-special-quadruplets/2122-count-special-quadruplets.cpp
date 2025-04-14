class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[nums[n-1]]++;

        for(int i = n-2; i >= 2; i--){
            for(int j = i-1; j >= 1; j--){
                for(int k = j-1; k >= 0; k--){
                    if(mp.count(nums[i] + nums[j] + nums[k])){
                        cnt += mp[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
            mp[nums[i]]++;
        }
        return cnt;
    }
};
