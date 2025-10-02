class Solution {
public:
    long long splitArray(vector<int>& nums) {

        // if there is a dip / valley shaped in the array, then it's not possible
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] <= nums[i-1] && nums[i] <= nums[i+1]){
                return -1;
            }
        }

        long long leftSum = nums[0];
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        int prev = nums[0];
        long long minAns = LLONG_MAX;

        for(int i = 1; i < nums.size()-1; i++){
            // cout << minAns << endl;

            if(nums[i] > nums[i-1] && nums[i] <= nums[i+1]){
                leftSum += nums[i];
                prev = nums[i];
                continue;  // it can't be a split => increasing wala part chal rha h => first try to get to the valid split point
            }
            
            if(minAns > labs((total-leftSum) - leftSum)){
                minAns = labs((total - leftSum) - leftSum);
            }
            
            if(nums[i] <= prev){
                break;
            }

            leftSum += nums[i];
            prev = nums[i];
        }

        if(minAns > labs((total-leftSum) - leftSum)){
            minAns = labs((total - leftSum) - leftSum);
        }

        return minAns;
    }
};