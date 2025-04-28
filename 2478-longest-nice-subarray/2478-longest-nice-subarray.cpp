class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // To check if the subarray is nice, we need the & of all possible pairs == 0
        // So, we maintain a mask, which will help in tracking the positions of all the 1's encountered till now, means OR of all
        // And we try to AND it with every element, before allowing it to be into our already nice subarray

        int n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        int mask = 0;

        while(r < n){

            while((mask & nums[r]) != 0){
                // keep shrinking
                mask = mask ^ nums[l];  // to negate the contribution of 1's in mask of the 'l' element, we use xor. bcz a^a=0
                l++;
            }

            ans = max(ans, r-l+1);
            mask |= nums[r];  // update mask
            r++;
        }

        return ans;
    }
};