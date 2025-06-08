class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        // my requirements are: 1. knowing the power of 2 element for each candidate 2. getting gcd 3. freq of power of 2's to know about the (minimum power of 2)Pmin ki freq in each subarray
        vector<int> powOf2(n, 0);
        for(int i = 0; i < n; i++){
            int val = nums[i];
            int cnt = 0;
            while(val % 2 == 0){
                cnt++;
                val /= 2;
            }
            powOf2[i] = cnt;
        }

        long long ans = LLONG_MIN;
        for(int l = 0; l < n; l++){
            ans = max(ans, 2LL*nums[l]*1);  // jab subarray [l,l] h, iska gcd = nums[l] hoga, and qki k>=1 always, to isko 2 se multiply kr denge, and length = 1

            int gcd_val = nums[l];
            int minPow2 = powOf2[l];
            vector<int> freqMinPow2(32);  // 2^31-1 hi ho skta at max
            freqMinPow2[powOf2[l]]++;  // current wale ki freq increment

            for(int r = l + 1; r < n; r++){
                gcd_val = gcd(gcd_val, nums[r]);
                minPow2 = min(minPow2, powOf2[r]);
                freqMinPow2[powOf2[r]]++;  // current wale ki freq increment

                if(freqMinPow2[minPow2] <= k){
                    // enough operations available h
                    ans = max(ans, 2LL*gcd_val*(r-l+1));
                }
                else{
                    // not enough operations
                    ans = max(ans, 1LL*gcd_val*(r-l+1));
                }
            }
        }

        return ans;
    }
};

// By looking at the constraints, we can be sure that o(n^2) would work
// The main tasks are getting the gcd of each subarray, length we can get easily
// And the main thing that makes the problem trickier is, to apply at most k operations on elements of subarray/array

// Now, if we didn't have any opxns given to us, we would have only needed the gcd of each subarray and len
// which we can easily calculate in O(n^2)
// gcd[l...r] => initialize gcd_val = arr[l], keep iterating from l to r, and update gcd_val = gcd(arr[i], gcd_val)
// and length is r-l+1 => score = gcd_val*len

// but the trick here is to apply the given operations at most k number of times
// let's analyze
// we can only apply operation once on each element
// let's say we applied operation on all the elements in the subarray(assuming we have k >= len)
// then what would happen => the gcd of the subarray will get multiplied by 2
// why, bcz the gcd is greatest common divisor, and it takes the minimum power of all the prime numbers of the subarray
// let's say array is containing [2^p1, 2^p2, 2^p3, 2^p4] => gcd will be equal to 2^(min{p1, p2, p3, p4})
// means if we apply operation on min power guy, the minimum will increment by 1, bcz we can only apply at most one operation on any element
// but what if we had multiple guys with minimum power of 2, in that case two cases might be there, if there are enough operations available for all of them => k >= number of minPower guys => gcd will multiplied by 2
// or case-2, when not enough operations available => k < number of minPower guys, means there will be some minPOwer guys left behind, and that will not let gcd multiply by 2 => gcd remains the same

// that's it, that's the solution