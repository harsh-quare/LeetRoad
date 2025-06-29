class Solution {
    const int mod = 1e9 + 7;
    void compute(vector<int>& powerOfTwo, int& n){
        powerOfTwo[0] = 1;
        for(int i = 1; i < n; i++){
            powerOfTwo[i] = (powerOfTwo[i-1]*2LL)%mod;
        }
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        // the order of elements won't matter, bcz we are only talking about min and max value in a subseq, so whether it's (1,2,5) or (5,1,2) or (2,5,1), it won't matter.
        sort(nums.begin(), nums.end());
        // Now we just try to fix the min value(means iterating from left to right), and finding max guy possible from each min element
        vector<int> powerOfTwo(n);
        compute(powerOfTwo, n);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int maxi = target - nums[i];
            // Now find out, what is the first guy greate than this maxi in [i...n-1]
            int id = upper_bound(nums.begin() + i, nums.end(), maxi) - nums.begin();

            int elesBtw = id - i - 1;
            if(elesBtw < 0) break;

            ans = (ans + powerOfTwo[elesBtw]) % mod;
        }

        return ans;
    }
};