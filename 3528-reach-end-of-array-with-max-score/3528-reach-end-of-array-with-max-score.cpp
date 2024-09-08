class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int i = 0;
        long long ans = 0;
        int n = nums.size();

        while(i < n){
            int j = i + 1;
            while(j < n && nums[j] < nums[i]){
                j++;
            }

            //in array
            if(j < n){
                ans += (long long)(j-i)*nums[i];
                i = j;
            }
            else{
                ans += (long long)(j-1-i)*nums[i];
                break;
            }
        }
        return ans;
    }
};