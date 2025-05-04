class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                cnt++;
                if(cnt > 1) return false;
                if(i == 0 || (nums[i-1] <= nums[i+1]))
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
            }
        }
        return true;
    }
};

// 3 cases: dip at index = 1; dip at index = n-1; dip at in between indices
// if the dips are either at 1 or n-1, and they are only one in the whole array, then its possible to make it non decreasing

// but if the dip is in between 2 to n-2, we need to check different cases
// one is [3,4,2,3]
// second is [-1,4,2,3]