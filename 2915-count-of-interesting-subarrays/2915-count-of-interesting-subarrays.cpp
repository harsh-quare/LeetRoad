class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        unordered_map<long long, int> mp; // cumSum_remainder -> count
        long long cumSum = 0;  // running sum => count of such indices satisfying the condn in [0,..,i]

        long long ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] % modulo == k){
                cumSum += 1;
            }
 
            int r1 = cumSum % modulo;
            int r2 = (r1 - k + modulo) % modulo;  // find r2

            ans += mp[r2];  // how many times, have I seen this r2 in the past

            mp[r1]++;
        }

        return ans;
    }
};