class Solution {
public:
    bool canRun(int mid, vector<int>& ct, vector<int>& rc, long long budget, vector<long long>& pref){
        // try all 'mid' sized windows and check if any one of them is possible or not?
        if(mid == 0) return true;
        deque<int> dq;  // stores indices of elements in decreasing order

        for(int i = 0; i < ct.size(); i++) {
            // remove out-of-window elements
            if (!dq.empty() && dq.front() <= i - mid)
                dq.pop_front();

            // maintain decreasing order
            while (!dq.empty() && ct[dq.back()] <= ct[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= mid - 1) {
                // compute sum of runningCosts
                long long sum = pref[i] - (i - mid >= 0 ? pref[i - mid] : 0);
                long long cost = ct[dq.front()] + mid * sum;

                if (cost <= budget)
                    return true;
            }
        }

        return false;
    }
        
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int l = 0, r = n;
        int ans = 0;

        vector<long long> pref(n, 0);
        pref[0] = runningCosts[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + runningCosts[i];
        }

        while(l <= r){
            int mid = l + (r-l)/2;

            if(canRun(mid, chargeTimes, runningCosts, budget, pref)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid-1;
            }
        }

        return ans;
    }
};