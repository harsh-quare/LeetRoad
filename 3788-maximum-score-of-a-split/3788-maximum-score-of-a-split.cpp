class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sufixMin(n);
        sufixMin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            sufixMin[i] = min(nums[i], sufixMin[i+1]);
        }

        long long prefSum = 0;
        long long ans = LLONG_MIN;
        for(int i = 0; i < n-1; i++){
            prefSum += nums[i];
            long long curAns = prefSum - sufixMin[i+1];

            ans = max(ans, curAns);
        }

        return ans;
    }
};