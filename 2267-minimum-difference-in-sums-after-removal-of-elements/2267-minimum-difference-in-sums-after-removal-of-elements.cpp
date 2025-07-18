class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int sz = nums.size();
        int n = sz/3;

        vector<long long> leftMinSum(sz, 0);
        vector<long long> rightMaxSum(sz, 0);

        priority_queue<int> mxHp;  // store minimums, pop maximums
        long long prefSum = 0;
        for(int i = 0; i < 2*n; i++){
            mxHp.push(nums[i]);
            prefSum += nums[i];

            if(mxHp.size() > n){
                prefSum -= mxHp.top();
                mxHp.pop();
            }

            leftMinSum[i] = prefSum;
        }

        priority_queue<int, vector<int>, greater<int>> mnHp;
        long long sufSum = 0;
        for(int i = sz-1; i >= n; i--){
            mnHp.push(nums[i]);
            sufSum += nums[i];

            if(mnHp.size() > n){
                sufSum -= mnHp.top();
                mnHp.pop();
            }

            rightMaxSum[i] = sufSum;
        }

        long long ans = LLONG_MAX;

        for(int i = n-1; i <= 2*n-1; i++){
            ans = min(ans, leftMinSum[i] - rightMaxSum[i+1]);
        }

        return ans;
    }
};