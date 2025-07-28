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