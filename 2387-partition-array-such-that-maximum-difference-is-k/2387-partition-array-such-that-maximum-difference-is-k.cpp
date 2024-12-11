class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // har ek subsequence me max and min ke baach me max diff k ho skta h, to har ek subseq me max number of values lene ka try krenge after sorting the array
        sort(nums.begin(), nums.end());
        int ans = 1;
        int subseq_min = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - subseq_min > k){
                ans++;
                subseq_min = nums[i];  //new starting point
            }
        }

        return ans;
    }
};