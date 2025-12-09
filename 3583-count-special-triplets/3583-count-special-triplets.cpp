class Solution {
public:
    const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        // 0 <= i < j < k < n
        // nums[i] = 2*nums[j] = 2*2*nums[k]
        // nums[k] = 2*nums[j]

        // nums[i] >= nums[j] <= nums[k]  && i < j < k
        
        // all 3 are in form of nums[j]. Iterate in the array, check for 'j'

        int n = nums.size();
        vector<int> dp1(n, 0);
        unordered_map<int, int> mp1;
        for(int j = 0; j < n; j++){
            if(mp1.find(nums[j] * 2) != mp1.end()){
                dp1[j] = (dp1[j] + mp1[nums[j] * 2]) % mod;
            }

            mp1[nums[j]]++;
        } 

        vector<int> dp2(n, 0);
        unordered_map<int, int> mp2;
        for(int j = n-1; j >= 0; j--){
            if(mp2.find(nums[j] * 2) != mp2.end()){
                dp2[j] = (dp2[j] + mp2[nums[j] * 2]) % mod;
            }

            mp2[nums[j]]++;
        } 

        long long ans = 0;
        for(int j = 1; j < n-1; j++){
            ans = (ans + 1LL * dp1[j] * dp2[j]) % mod;   // we need to find the combinations => left * right
        } 

        return ans;
    }
};