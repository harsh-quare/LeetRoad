class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for(int& x: nums){
            maxOr |= x;
        }

        int totalSubsets = 1 << n;  // 2^n
        int cntMaxOr = 0;

        // all possible subsets
        for(int mask = 0; mask < totalSubsets; mask++){

            int curOr = 0;
            for(int i = 0; i < n; i++){
                if(((mask >> i) & 1) == 1){
                    curOr |= nums[i];
                }
            }

            if(curOr == maxOr) cntMaxOr++;
        }

        return cntMaxOr;
    }
};

// Calculate the total number of possible subsets by left-shifting 1 by the length of nums, and store it in totalSubsets.
// Initialize a variable subsetsWithMaxOr to 0 to count subsets with maximum OR value.
// Iterate through all possible subset combinations, from 0 to totalSubsets - 1:
// Initialize currentOrValue to 0 for each subset.
// Iterate through each index i of the input array nums:
// If the i-th bit of the current subset mask is set:
// Perform a bitwise OR of currentOrValue with the i-th element of nums.
// If currentOrValue is equal to maxOrValue.
// Increment subsetsWithMaxOr.
// Return the final count stored in subsetsWithMaxOr.