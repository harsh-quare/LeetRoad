class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        int n= nums.size();

        stack<int> st;

        // storing values in decreasing order in stack
        for(int i = 0; i < n; i++){
            if(st.empty() || nums[i] < nums[st.top()]){
                st.push(i);
            }
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                int idx = st.top();
                ans = max(ans, i-idx);
                st.pop();
            }
        }

        return ans;
    }
};