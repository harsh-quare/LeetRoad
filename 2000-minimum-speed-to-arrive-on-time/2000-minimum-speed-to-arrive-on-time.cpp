class Solution {
public:
    bool isValid(int mid, vector<int>& nums, double hr){
        int n = nums.size();
        double calc = 0;
        for(int i = 0; i < n-1; i++){
            // calc = calc + ceil(nums[i] / mid);
            // use this instead of ceil function
            if(nums[i] % mid == 0) calc += nums[i] / mid;
            else calc += nums[i] / mid + 1;
        }

        // last train me ceil value nhi, actual value chahiye
        calc = calc + (double)nums[n-1] / (mid * 1.0);

        return calc <= hr;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isValid(mid, dist, hour)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};