class Solution {
public:
    bool check(vector<int>& nums) {
        int pivotId = -1;

        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(pivotId != -1) return false;  // already ek pivot mil gya h
                pivotId = i;
            }
        }

        if(pivotId == -1) return true;  // no pivots, already sorted
        if(pivotId != -1 && nums[nums.size()-1] <= nums[0]) return true;  // single pivot, and rotated sorted
        else return false;
    }
};