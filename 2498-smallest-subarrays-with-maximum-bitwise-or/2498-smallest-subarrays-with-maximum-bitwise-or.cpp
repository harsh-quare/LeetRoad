class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int curOr = 0;
        vector<int> lastOccCurBit(32, -1);
        for(int i = n-1; i >= 0; i--){
            curOr |= nums[i];

            for(int b = 0; b < 31; b++){
                if(((nums[i] >> b) & 1) == 1){
                    lastOccCurBit[b] = i;   // the latest place this bit has occured is current index, it will help us getting the minimum point we need to go, to get the value of maxOr from 'i'
                }
            }

            int maxLastBitIndex = i;
            for(int b = 0; b < 31; b++){
                maxLastBitIndex = max(maxLastBitIndex, lastOccCurBit[b]);
            }

            ans[i] = maxLastBitIndex - i + 1;
        }

        return ans;
    }
};