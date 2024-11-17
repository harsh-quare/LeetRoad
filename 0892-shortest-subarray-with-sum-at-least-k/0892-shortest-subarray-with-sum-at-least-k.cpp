class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n, 0);
        int mini = INT_MAX;
        deque<int> dq;

        for(int i = 0; i < n; i++){
            if(i == 0) pref[i] = nums[i];
            else pref[i] = pref[i-1] + nums[i];

            if(pref[i] >= k) mini = min(mini, i-0+1);  //if this exceeds k, then its also a valid answer, update the answer

            //try to shrink the window. We are storing the valid increasing subarray part in our deque, so try to shrink windo to get better answer
            while(!dq.empty() && pref[i] - pref[dq.front()] >= k){
                mini = min(mini, i - dq.front());
                dq.pop_front();
            }

            // if you encounter a dip, means a negative value, this will not be resulting in better answer, bcz we can get better answer by not taking this value, so remove that dip, i.e. all those negative values, to make subarray only increasing
            while(!dq.empty() && pref[i] < pref[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return mini == INT_MAX ? -1 : mini;
    }
};