class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Using Binary Search
        int n = nums.size();

        vector<int> lis_arr;
        lis_arr.push_back(nums[0]);

        for(int i = 1; i<n; i++){
            //Add the value into ans array when a larger value is encountered
            if(lis_arr.back() < nums[i]){
                lis_arr.push_back(nums[i]);
            }
            else{
                //Update the ans vector, when a smaller value is encountered
                //How?-> Using lower_bound iterator to get the value that is just greater than or equal to the current value of nums
                //to get the index of that point, subtract the address of beginning of ans array, and then update the value at that index
                int idx = lower_bound(lis_arr.begin(), lis_arr.end(), nums[i]) - lis_arr.begin();
                lis_arr[idx] = nums[i];
            }
        }

        return lis_arr.size();
    }
};