class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int distArr = st.size();
        
        for(int i = 0; i < n; i++){
            unordered_set<int> cur;
            for(int j = i; j < n; j++){
                cur.insert(nums[j]);
                if(cur.size() == distArr) ans++;
            }
        }

        return ans;
    }
};