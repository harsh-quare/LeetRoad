class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1;
        int suf = 1;

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(pref == 0) pref = 1;
            if(suf == 0) suf = 1;

            pref *= nums[i];
            suf *= nums[n-i-1];

            maxi = max(maxi, max(pref, suf));
        }

        return maxi;
    }
};
// case-1: all positive numbers: product of all array elements
// case-2: if it contains positive numbers and even number of negative elements: product of all array elements
// case-3: if it contains positive numbers and odd number of negative elements: In this case, we need to leave out one negaative element and calculate remaining prod
// ex: [1,2,-1,3,-4,4,-1]
// if we leave out -1, then there can be two answers: prefProd & suffProd
// similarly, if we leave out -4, again we have two options, prefProd and suffProd

// case-4: if it contains zeros as well, we will start a new subarray whenever we encounter 0, means resetting pref and suf prod to 1, because if we take 0, it will just make the prod to 0

// All the negative and 0 wali prod will be updated in maxi calculation