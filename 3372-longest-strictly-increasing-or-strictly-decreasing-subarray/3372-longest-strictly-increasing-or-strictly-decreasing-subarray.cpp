class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_d = 1, max_i = 1;
        int cur_d = 0, cur_i = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                cur_d++;
                cur_i = 0;
            }
            else if(nums[i] > nums[i-1]){
                cur_i++;
                cur_d = 0;
            }
            else{
                cur_i = 0, cur_d = 0;
            }

            max_d = max(max_d, cur_d + 1);
            max_i = max(max_i, cur_i + 1);
        }

        return max(max_i, max_d);
    }
};