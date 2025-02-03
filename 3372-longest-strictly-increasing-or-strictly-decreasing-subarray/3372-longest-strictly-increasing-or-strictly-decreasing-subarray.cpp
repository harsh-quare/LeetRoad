class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_d = 1, max_i = 1;
        int cur_d = 1, cur_i = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                cur_d++;
                cur_i = 1;
            }
            else if(nums[i] > nums[i-1]){
                cur_i++;
                cur_d = 1;
            }
            else{
                cur_i = 1, cur_d = 1;
            }

            max_d = max(max_d, cur_d);
            max_i = max(max_i, cur_i);
        }

        return max(max_i, max_d);
    }
};