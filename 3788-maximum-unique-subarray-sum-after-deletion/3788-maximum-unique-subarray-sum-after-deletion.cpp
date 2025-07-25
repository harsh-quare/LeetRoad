class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;
        int maxNonPos = INT_MIN;
        for(int x: nums){
            if(x <= 0){
                maxNonPos = max(maxNonPos, x);
            }
            else{
                if(!st.count(x)){
                    ans += x;
                    st.insert(x);
                }
                else continue;
            }
        }

        return (st.empty()) ? maxNonPos : ans;
    }
};