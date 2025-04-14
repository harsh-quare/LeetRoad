class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[nums[n-1] - nums[n-2]]++;

        for(int b = n-3; b >= 1; b--){
            for(int a = b-1; a >= 0; a--){
                cnt += mp[nums[a] + nums[b]];
            }

            for(int x = n-1; x > b; x--){
                mp[nums[x]-nums[b]]++;
            }
        }
        return cnt;
    }
};
