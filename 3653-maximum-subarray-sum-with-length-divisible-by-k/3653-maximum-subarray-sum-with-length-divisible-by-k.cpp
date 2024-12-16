class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // Break down the problem
        // we need subarray sum: use prefix sum: subarr[i...j]: sum = (prefS[j] - prefS[i-1])
        // we need to maximize the prefSum: minimize the prefS[i-1]
        // we also need the size of subarray and condn: divisible by K
        // means we also need the starting pt of subarray 'i' such that the size of subarray becomes divisible by K
        // but if we try to manually take different size subarrays and check divisible by K condn it will be slow
        
        // hmm!! we need something that can help us get the valid guy(starting pt, resulting in size divisible by k)
        // which is also storing minPref[i-1] value. 
        // Maybe we can store all the minPref values for each value of 0...k-1 : because modulo value will be between 0 to k-1

        int n = nums.size();
        vector<long long> minPrefSum(k);
        for(int i = 0; i < k; i++){
            minPrefSum[i] = LLONG_MAX;
        }
        minPrefSum[k-1] = 0;

        long long pref = 0;
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; i++){
            pref += nums[i];
            
            //once you cross index = k, then only you can take the prefSum and minPrefSum for that remainder
            if(i >= k){
                ans = max(ans, pref - minPrefSum[i % k]);
            }
            else if(i == k-1){    //means we will get the starting pt as index = 0, or i-1 = -1, where prefSum[-1] = 0
            // that will make the length = k and this will be our first subarray of length k in the array
                ans = max(ans, pref - 0);
            }
            
            minPrefSum[i % k] = min(minPrefSum[i % k], pref);  //keep maintaining the minPrefSum for different values of [0...k-1]
        }

        return ans;
    }
};