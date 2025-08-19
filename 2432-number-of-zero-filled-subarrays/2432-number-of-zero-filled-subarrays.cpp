class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0;

        while(j < n){

            while(i < n && nums[i] != 0){
                j++;
                i++;
            }

            while(j < n && nums[j] == 0){
                ans += (j - i + 1);
                j++;
            }
            
            i = j;
        }

        return ans;
    }
};