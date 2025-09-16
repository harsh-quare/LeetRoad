class Solution {
public:
    int findGCD(int a, int b){
        if(b == 0) return a;
        return findGCD(b, a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;  // behaves as a stack
        ans.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            long cur = nums[i];

            while(!ans.empty() && findGCD(cur, ans.back()) > 1){
                int prev = ans.back();
                ans.pop_back();
                cur = (1LL * cur * prev) / findGCD(cur, prev);
            }
            ans.push_back(cur);
        }

        return ans;
    }
};