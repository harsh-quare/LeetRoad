class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        // all evens, or all odds, or seq of alternate odd and evens

        int even = 0, odd = 0;
        int evenOddSeqLen = 1;  // 1 length to hamesha rahegi, either odd or even
        int prev = nums[0];

        for(int i = 0; i < n; i++){
            even += (nums[i] % 2 == 0);
            odd += (nums[i] % 2 == 1);
            
            if(i >= 1 && nums[i] % 2 != prev % 2){ // current and prev ki parity different
                evenOddSeqLen++;
                prev = nums[i];
            }
        }

        return max(evenOddSeqLen, max(even, odd));
    }
};