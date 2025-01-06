class Solution {
public:
    const int mod = 1e9+7;
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(); // Length of the input array
        int ans = 0; // Initialize the count of valid splits to 0

        // Step 1: Compute the prefix sum array
        vector<int> pref(n, 0); // Prefix sum array
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {    
            pref[i] = pref[i - 1] + nums[i];
        }

        // Step 2: Iterate through all possible positions for the left partition
        for (int l = 0; l < n - 2; l++) {
            // Calculate the sum of the left partition
            int left_sum = pref[l];

            // If the left partition sum is already too large to allow a valid split,
            // we can stop further iterations
            if (left_sum * 3 > pref[n - 1]) break;

            // Step 3: Find the range of valid mid partitions

            // Lower bound for the mid partition:
            // Find the first index where the mid partition sum >= left_sum
            int low_id = lower_bound(pref.begin() + l + 1, pref.end(), left_sum * 2) - pref.begin();

            // Upper bound for the mid partition:
            // Find the first index where the mid partition sum > (remaining total sum) / 2
            int up_id = upper_bound(pref.begin() + l + 1, pref.begin() + n - 1, 
                                    left_sum + (pref[n - 1] - left_sum) / 2) - pref.begin();

            // Step 4: Add the count of valid mid partitions for this left partition
            ans += max(0, up_id - low_id); // Add the range size of valid mid partitions
            ans %= mod; // Take modulo to avoid overflow
        }

        // Step 5: Return the total count of valid splits
        return ans;
    }
};
