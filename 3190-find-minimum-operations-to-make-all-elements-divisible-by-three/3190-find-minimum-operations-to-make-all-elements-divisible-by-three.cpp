class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int x: nums){
            int a = x % 3;
            int b = 3 - a;

            ans += min(a, b);
        }

        return ans;
    }
};