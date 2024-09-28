class Solution {
public:
    int getSum(int val){
        int sum = 0;
        while(val > 0){
            sum += val % 10;
            val /= 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int newVal = getSum(nums[i]);
            mini = min(mini, newVal);
        }

        return mini;
    }
};