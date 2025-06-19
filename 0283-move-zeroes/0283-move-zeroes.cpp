class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // from left to right, we want to maintain the order of non zero elements
        // so what we do is use two pointers, first will be track where to keep the next non zero element, and second will traverse the array

        int nonZeroPos = 0, j = 0;
        int n = nums.size();
        while(j < n){
            if(nums[j] != 0){
                swap(nums[nonZeroPos], nums[j]);
                nonZeroPos++;
            }
            j++;
        }

        // now all the non-zero eles are at the front of the array, and in their relative order
        // that means, all the zeros are back of the array
        // so we are done
    }
};