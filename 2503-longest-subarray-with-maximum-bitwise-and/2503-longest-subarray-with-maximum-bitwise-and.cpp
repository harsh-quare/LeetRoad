class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = nums[0];
        int maxLen = 1;
        int curLen = 1;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > maxEle){
                //agar ek greater element mil gya, to purana wale ka contribution matter nhi krta isliye maxLen ko update nhi krenge, and 1 se start kr denge
                curLen = 1;
                maxLen = 1;
                maxEle = nums[i];
                // cout << "i" << endl;
            }
            else if(nums[i] == maxEle){
                curLen++;
                maxLen = max(maxLen, curLen);
                // cout << "ei" << endl;
            }
            else{
                curLen = 0;
                // cout << "e" << endl;
            }
        }
        return maxLen;
    }
};