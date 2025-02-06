class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pref(n, 0), suf(n, 0);
        pref[0] = nums[0];
        suf[0] = nums[n-1];
        for(int i = 1; i < n; i++){
            int bck = n-1-i;
            pref[i] = pref[i-1] + nums[i];
            suf[i] = suf[i-1] + nums[bck];
        }

        if(pref[n-1] == x) return n;

        int ans = n;  // maximum number of operations we can make, bcz after n operations, all elements will be deleted.
        for(int i = 0; i < n; i++){
            // if you got it by removing from only one end
            if(pref[i] == x || suf[i] == x){
                ans = min(ans, i+1);
            }

            // if we removed elements from both the ends
            int fromStart = pref[i];
            int fromBack = x - fromStart;
            int id_back = lower_bound(suf.begin(), suf.end(), fromBack) - suf.begin();
            if(id_back != n && suf[id_back] == fromBack){
                ans = min(ans, id_back+1 + i+1);
            }
        }

        return ans == n ? -1 : ans;
    }
};