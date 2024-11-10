class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> hash(32, 0);

        int l = 0, r = 0;
        int n = nums.size();
        int curOr = 0;
        int ans = INT_MAX;

        while(r < n){
            curOr |= nums[r];

            for(int i = 0; i < 32; i++){
                if(nums[r] & (1 << i)){
                    hash[i]++;
                }
            }

            // curOr >= k, try to shrink the window
            while(l <= r && curOr >= k){
                ans = min(ans, r-l+1);

                //remove nums[l] from the window
                for(int i = 0; i < 32; i++){
                    if(nums[l] & (1 << i)){
                        hash[i]--;
                        if(hash[i] == 0){
                            curOr -= (1 << i); //if the count of this bit becomes zero, remove it from or
                        }
                    }
                }

                l++;  //shrinking the window from the left
            }
            r++;  //expand the window by moving the right pointer
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};