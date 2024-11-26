class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int i, j, n = nums.size(), g = 0;
        for(i = 0; i < n; i++){
            g = nums[i];
            for(j = i; j < n; j++){
                g = __gcd(g, nums[j]);     //take gcd all number from i...to...j
                if(g == k) ans++;          //if gcd == k than increment ans by one
                else if(g < k) break; //if gcd < k than break subarray's loop because we cann't find a subarray whose gcd==k
            }
        }
        return ans;
    }
};