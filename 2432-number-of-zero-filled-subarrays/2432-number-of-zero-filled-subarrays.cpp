class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long consZeros = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                ans += consZeros * (consZeros + 1) / 2;
                consZeros = 0;  // reset 
            }
            else{
                consZeros++;
            }
        }

        ans += consZeros * (consZeros + 1) / 2;  // last stretch

        return ans;
    }
};