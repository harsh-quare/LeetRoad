class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // I will go to every binary string available, and will try to make my string along the way by, differentiating one bit from each string
        string ans = "";
        for(int i = 0; i < n; i++){
            char cur = nums[i][i];  // 0th char of 0th string, 1st char of 1st string, 2nd char of 2nd string, and so on..
            ans += (cur == '0' ? '1' : '0');
        }

        return ans;
    }
};