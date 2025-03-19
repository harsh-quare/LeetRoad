class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i >= n-2 && nums[i] == 0) return -1;
            else{
                if(nums[i] == 0){
                    ans++;
                    nums[i] = !nums[i];
                    nums[i+1] = !nums[i+1];
                    nums[i+2] = !nums[i+2];
                }
            }
        }

        return ans;
    }
};