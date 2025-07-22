class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxUnqSum = 0;
        int curSum = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;
            curSum += nums[j];

            while(mp[nums[j]] > 1){   // jb tk duplicates h curr window me current element ke
                // left se shrink krte jao, and left se duplicates hatao current element ke
                mp[nums[i]]--;
                curSum -= nums[i];
                i++;
            }

            maxUnqSum = max(maxUnqSum, curSum);
            j++;
        }
        
        return maxUnqSum;
    }
};