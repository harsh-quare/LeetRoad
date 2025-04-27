class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;

        int minId = -1, maxId = -1, culId = -1;  // latest index of minK val, maxK val, and a value which is out of this range

        // We try to calculate for each index, how many subarrays are good, ending at that index
        for(int i = 0; i < n; i++){
            if(nums[i] == minK) minId = i;
            if(nums[i] == maxK) maxId = i;
            if(nums[i] > maxK || nums[i] < minK) culId = i;

            int smaller = min(minId, maxId);
            long long temp = smaller - culId;

            ans += (temp <= 0) ? 0 : temp;
        }

        return ans;
    }
};