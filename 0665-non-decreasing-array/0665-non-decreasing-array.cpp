class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt= 0;
        int p = -1;
        int n = nums.size();

        for(int i = 1; i <= n-1; i++){
            if(nums[i] < nums[i-1]){
                cnt++;
                p = i;
            }
        }

        if(cnt > 1) return false;
        if(p == -1 || (cnt <= 1 && (p == 1 || p == n-1))) return true;

        // check for inbetween dips
        if(cnt <= 1 && (nums[p-1] <= nums[p+1])) return true;
        if(cnt > 1 || (nums[p-2] > nums[p])) return false;

        return true;
    }
};

// 3 cases: dip at index = 1; dip at index = n-1; dip at in between indices
// if the dips are either at 1 or n-1, and they are only one in the whole array, then its possible to make it non decreasing

// but if the dip is in between 2 to n-2