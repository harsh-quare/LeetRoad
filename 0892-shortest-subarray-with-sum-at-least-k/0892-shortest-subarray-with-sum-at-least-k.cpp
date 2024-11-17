class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long rsum = 0;
        int mini = INT_MAX;
        deque<pair<int, long long>> dq;

        for(int i = 0; i < n; i++){
            rsum += nums[i];

            if(rsum >= k) mini = min(mini, i-0+1);
    
            while(!dq.empty() && rsum-dq.front().second >= k){
                mini = min(mini, i - dq.front().first);
                dq.pop_front();
            }
            
            while(!dq.empty() && rsum < dq.back().second){
                //dip aa gya, isko consider mt kro, isse better answer hame mil jayega 100%
                dq.pop_back();
            }
            
            dq.push_back({i, rsum});
        }

        return mini == INT_MAX ? -1 : mini;
    }
};