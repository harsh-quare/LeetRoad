class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // har ek subsequence me max and min ke baach me max diff k ho skta h, to har ek subseq me max number of values lene ka try krenge after sorting the array
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, ans = 0;

        while(right < nums.size()){
            if(nums[right] - nums[left] > k){
                ans++;  //one subseq is completed, no more values can be added in this subseq
                left = right;  //shrink the window: new subseq will start from this point only
            }
            right++;
        }

        return ans + 1;  //+1 for last subseq
    }
};