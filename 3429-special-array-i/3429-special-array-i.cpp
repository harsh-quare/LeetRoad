class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        // Check all the adjacent pairs, and check bits
        bool same = false;
        for(int i = 0; i < n-1; i++){
            int x = nums[i];
            int y = nums[i+1];

            if((x & 1) == (y & 1)){
                same = true;
                break;
            }
        }

        return same == false;
    }
};