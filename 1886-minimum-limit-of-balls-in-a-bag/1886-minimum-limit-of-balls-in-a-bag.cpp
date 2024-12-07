class Solution {
public:
    //can you fit all the balls having max as mid in the given maxsize
    bool canFit(int mid, vector<int>& nums, int maxOps){
        int opsCnt = 0;  //number of operations needed to divide all greater values into maxVal as mid
        for(int& x: nums){
            opsCnt += (x / mid);  // x=7, mid=4: can be divided into 4 and 3: 1 ops; or x = 16, mid = 4: 4,4,4,4: 3 ops
            if(x % mid == 0) opsCnt--;
            if(opsCnt > maxOps) return false;
        }

        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        //search space is the 'min number of bags' with which you can put balls fitting in maxSize

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(canFit(mid, nums, maxOperations)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};