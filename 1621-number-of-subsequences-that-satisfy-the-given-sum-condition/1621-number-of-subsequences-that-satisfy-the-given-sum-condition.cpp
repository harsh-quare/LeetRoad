class Solution {
    const int mod = 1e9 + 7;
    void compute(vector<int>& powerOfTwo, int &n){
        powerOfTwo[0] = 1;
        for(int i = 1; i < n; i++){
            powerOfTwo[i] = (powerOfTwo[i-1]*2LL) % mod;
        }
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        // the order of elements won't matter, bcz we are only talking about min and max value in a subseq, so whether it's (1,2,5) or (5,1,2) or (2,5,1), it won't matter.
        sort(nums.begin(), nums.end());
        // Now we just try to use two pointers for kind of a twosum problem, to find the target value
        int l = 0, r = n-1;
        int ans = 0;
        vector<int> powerOfTwo(n);
        compute(powerOfTwo, n);
        while(l <= r){
            if(nums[l] + nums[r] > target){  // find smaller value
                r--;
            }
            else{
                // max 'r' bnda jo valid h, to iss 'r' and 'l' wale combo me l...r me saare elements ke paas choice h, to include or to not include => 2^(r-l) combinations
                ans = (ans + powerOfTwo[r-l]) % mod; 

                l++;  // ab iss min wale bnde se saare subseq bna liye, to next pe chale jao
            }
        }

        return ans;
    }
};