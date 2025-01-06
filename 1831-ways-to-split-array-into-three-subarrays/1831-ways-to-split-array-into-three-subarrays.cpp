class Solution {
public:
    const int mod= 1e9+7;
    // pref[i] <= pref[j] - pref[i] <= pref[n-1] - pref[j]

    // pref[j] >= 2*pref[i]
    // pref[j] <= (pref[n-1] + pref[i]) / 2

    // we have an lower and upper bound for 'j', mid subarray
    // use binary search to find left and right boundary of 'j'
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        // every time, I need sum of all the partitions subarray
        // to calculate the sum of a range, we use prefix sum.

        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){    
            pref[i] = pref[i-1] + nums[i];
        }

        // for each first_partition_idx, we try to look for the next index possible in the array which will have a mid sum and right sum > left sum

        for(int l = 0; l < n-2; l++){
            int left_sum = pref[l] - 0;
            
            if(left_sum * 3 > pref[n-1]) break;

            // Find the first index where the sum of mid subarray will be valid, 
            // means at least equal to left_sum, that's why 
            // we write left_sum(bcz of prefix property) and + left_sum(min valid sum of this subarray)
            // ensures: mid_sum ≥ left_sum
            // The first valid starting position of the mid subarray, ensuring mid_sum >= left_sum.
            // low_id (First Valid Mid Partition):
            // start from next index of 'l' => l + 1
            int low_id = lower_bound(pref.begin() + l + 1, pref.end(), left_sum + left_sum) - pref.begin();

            // Now we need to find the largest index up_id such that the mid partition leaves enough sum for the right partition
            // This ensures: mid_sum ≤ (total_sum − left_sum) / 2
            // The upper_bound step ensures that the mid subarray does not exceed half of the remaining total sum after accounting for the left subarray. This guarantees a valid split where: mid_sum ≤ right_sum
            // The exclusive upper bound for the mid subarray, ensuring mid_sum <= (total_sum - left_sum) / 2.
            // It represents the end of the valid range for the mid subarray.
            // The first index where the prefix sum exceeds the condition for the mid subarray, ensuring enough sum is left for the right subarray.
            // up_id (First Invalid Mid Partition):
            int up_id = upper_bound(pref.begin() + l + 1, pref.begin() + n - 1, left_sum + ((pref[n-1] - left_sum) / 2)) - pref.begin();
            
            ans += (max(0, (up_id - low_id))) % mod; 
            //calculate the number of valid mid partitions for the current left partition (up_id - low_id).
            ans = ans % mod;
        }

        return ans;
    }
};

// we know, total_sum = left + mid + right
// right = total - left - mid
// if we want to ensure mid <= right
// --> mid <= total - mid - left
// --> 2*mid <= total - left
// --> mid <= (total - left) / 2
// So we try to find the first guy 