class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> res(n);

        //step-1: Find the total XOR
        int xor_val = 0;
        for(int i = 0; i < n; i++){
            xor_val ^= nums[i];
        }

        //to find the flip of the overall xor, first find the mask having all 1s, equal to number of bits in the xor
        //why flip: let xor = 1010, when it will be maximized? the moment we xor it with 0101(flip of 1010), it gets to the max value possible

        int mask = ((1 << maximumBit) - 1);  // mask = 2^maximumBit-1

        for(int i = 0; i < n; i++){
            int k = xor_val ^ mask;  //this will give the flipped value of xor, i.e. our best k
            res[i] = k;

            xor_val ^= nums[n-i-1]; //xor with last element before going to next iteration, to remove last element in each iteration 
        }

        return res;
    }
};