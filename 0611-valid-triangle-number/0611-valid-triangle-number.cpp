class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Better
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            int l = 0, r = i-1;

            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    ans += (r - l);
                    r--;
                }
                else{
                    l++;
                }
            }
        }

        return ans;
    }
};

//  Before sorting: Need to check 3 conditions
//  a + b > c AND b + c > a AND a + c > b

//  After sorting (a ≤ b ≤ c): Only need 1 condition!  
//  a + b > c  (other two automatically satisfied!)