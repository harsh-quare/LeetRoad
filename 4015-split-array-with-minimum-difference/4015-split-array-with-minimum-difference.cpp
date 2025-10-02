class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        long long left = 0, right = 0;

        while(l < n-1 && nums[l] < nums[l+1]){
            left += nums[l];
            l++;
        }

        while(r > 0 && nums[r - 1] > nums[r]){
            right += nums[r];
            r--;
        }

        // if only single point of split possible => 2,3,4,3,1
        if(l == r){
            // option-1: take split point in left part
            long long op1 = abs((left + nums[l]) - right);
            long long op2 = abs(left - (right + nums[l]));

            return min(op1, op2);
        }
        // flat peak => 3,4,5,5,4,3 => 2 equal middle elements => 3,4,5 and 5,4,3 => this is valid split
        else if(r - l == 1 && nums[l] == nums[r]){
            return abs(left - right);
        }

        return -1;  // invalid => a valley present in the array
    }
};