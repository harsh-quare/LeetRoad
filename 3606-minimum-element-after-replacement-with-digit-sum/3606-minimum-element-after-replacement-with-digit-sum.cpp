class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            string s = to_string(nums[i]);
            int newVal= 0;
            for(auto c: s){
                newVal += (c-'0');
            }
            mini = min(mini, newVal);
        }

        return mini;
    }
};