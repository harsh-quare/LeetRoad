class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefSum = 0;
        vector<long long> minPrefSum(k);  //will be storing minPrefSum values for all the i%k positions

        for(int i = 0; i < k; i++){
            minPrefSum[i] = LLONG_MAX;
        }

        minPrefSum[k-1] = 0;  //pref[-1] = 0;

        long long maxSum = LLONG_MIN;
        for(int i = 0; i < n; i++){
            prefSum += nums[i];

            int rem = i % k;
            if(i >= k){
                // pref[j] - minPfSum[i%k]
                // minPfSum[i%k] is making it easier for us to look all the %k values for current i, and we take/maintain min of all, bcz we need to maximize the prefSum, and the minPfSum is what we are subtracting from it, so we need to minimize the value we are subtracting 
                maxSum = max(maxSum, prefSum - minPrefSum[rem]);
            }
            else if(i == k-1){
                maxSum = max(maxSum, prefSum);
            }

            //update the minPrefSum for current value of i%k
            minPrefSum[rem] = min(minPrefSum[rem], prefSum);
        }

        return maxSum;
    }
};