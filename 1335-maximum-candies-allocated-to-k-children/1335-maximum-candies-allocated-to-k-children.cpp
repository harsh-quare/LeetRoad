class Solution {
public:
    bool isValid(int mid, vector<int>& nums, long long k, int n){
        long long chd = 0;
        for(int i = 0; i < n; i++){
            chd += (long long) nums[i] / mid;
        }

        if(chd < k) return false;
        return true;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long tot = accumulate(candies.begin(), candies.end(), 0LL);
        if(tot < k) return 0;

        // Now we have atleast 'k' amount of candies, means at least we can give 1 candy to each child.
        int low = 1;  // lowest we can give is 1
        int high = *max_element(candies.begin(), candies.end());  // max we can give is qual to the number of largest sized candy

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isValid(mid, candies, k, n)){
                // it might be the possible answer, store it and try higher number
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return res;
    }
};