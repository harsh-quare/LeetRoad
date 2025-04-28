class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // To check if the subarray is nice, we need the & of all possible pairs == 0
        // So, we maintain a mask, which will help in tracking the positions of all the 1's encountered till now, means OR of all
        // And we try to AND it with every element, before allowing it to be into our already nice subarray

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int mask = 0;

            for(int j = i; j < n; j++){
                if((mask & nums[j]) != 0) break;  // means we can't get anymore nice subarr with 'i' as starting point

                mask |= nums[j];    // update mask with current element's 1's positions
                ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};