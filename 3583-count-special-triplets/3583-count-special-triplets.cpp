class Solution {
public:
    const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        // 0 <= i < j < k < n
        // nums[i] = 2*nums[j] = 2*2*nums[k]
        // nums[k] = 2*nums[j]

        // nums[i] >= nums[j] <= nums[k]  && i < j < k
        
        // all 3 are in form of nums[j]. Iterate in the array, check for 'j'

        // calculate frequency of each element in nums
        // and while iterating, maintain another hash for frequency of elements till current index => left side elemen cnt
        // and right = total - left

        int n = nums.size();
        unordered_map<int, int> right;
        unordered_map<int, int> left;

        for(int x: nums) right[x]++;

        long long ans = 0;
        for(int x: nums){
            right[x]--;   // should only contain rights, remove lefts from it
            int leftCnt = left[2*x];
            int rightCnt = right[2*x];
            ans = (ans + 1LL * leftCnt * rightCnt) % mod;

            left[x]++;
        }

        return ans % mod;
    }
};