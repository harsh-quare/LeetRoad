class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        // array ko %2 krdo saaare elements ko => 0,1,0,1...
        // we have 3 options: either the subseq will be a sequence of pair of {0,1}
        // or it will be all 0s, or it will be all 1s
        // return maximum length among three

        int zeros = (nums[0] % 2 == 0), ones = (nums[0] % 2 == 1);
        int zeroOneSeqLen = 1;  // atleast one to hamesha hoga, either 0 or 1
        bool prevZero = (nums[0] % 2 == 0); // 0 means prev was 1, and 1 means prev was 0

        for(int i = 1; i < n; i++){
            zeros += (nums[i] % 2 == 0);
            ones += (nums[i] % 2 == 1);
            
            if((nums[i] % 2 == 0 && prevZero == 0) || (nums[i] % 2 == 1 && prevZero == 1)){
                zeroOneSeqLen++;
                prevZero = (nums[i] % 2 == 0);
            }
            else continue;
        }

        return max(zeroOneSeqLen, max(zeros, ones));
    }
};