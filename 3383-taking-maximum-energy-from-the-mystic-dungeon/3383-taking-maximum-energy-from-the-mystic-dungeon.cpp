class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // we have to maximize the total gain energy by choosing some starting point and making 'k' step jumps until we can't.
        // The idea is to start from end of array, bcz we are unsure about the starting point, so we will start from back
        // bcz we are sure that we will end in between of (n-1-k) to (n-1), the last 'k' size window => it's for sure
        // that's why we will start from back, and keep storing gain in an array and then finally return maxi value from array
        // start from behind => (n-1) -> 0. 
        
        int n = energy.size();
        vector<int> final = energy;
        int ans = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            if(i+k >= n){
                ans = max(ans, final[i]);
            }
            else{
                // take contribution from (i+k) guy
                final[i] += final[i+k];
                ans = max(ans, final[i]);
            }
        }

        return ans;
    }
};