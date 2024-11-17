class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long rsum = 0;
        int mini = INT_MAX;
        deque<pair<int, long long>> dq;

        for(int i = 0; i < n; i++){
            rsum += nums[i];  //update the running sum

            if(rsum >= k) mini = min(mini, i-0+1);  //if this exceeds k, then its also a valid answer, update the answer

            //try to shrink the window. We are storing the valid increasing subarray part in our deque, so try to shrink windo to get better answer
            while(!dq.empty() && rsum - dq.front().second >= k){
                mini = min(mini, i - dq.front().first);
                dq.pop_front();
            }

            // if you encounter a dip, means a negative value, this will not be resulting in better answer, bcz we can get better answer by not taking this value, so remove that dip, i.e. all those negative values, to make subarray only increasing
            while(!dq.empty() && rsum < dq.back().second){
                dq.pop_back();
            }

            dq.push_back({i, rsum});
        }

        return mini == INT_MAX ? -1 : mini;
    }
};