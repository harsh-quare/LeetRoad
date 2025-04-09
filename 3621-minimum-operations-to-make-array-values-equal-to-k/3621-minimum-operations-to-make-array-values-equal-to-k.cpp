class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;  // will contain greater values than k
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > k) st.insert(nums[i]);
            mini = min(mini, nums[i]);
        }

        if(mini < k) return -1;

        return st.size();
    }
};