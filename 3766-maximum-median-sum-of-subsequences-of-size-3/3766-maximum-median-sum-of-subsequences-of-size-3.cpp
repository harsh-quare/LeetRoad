class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());

        // for(int i = 0; i < n; i++){
        //     cout << nums[i] << endl;
        // }

        int cnt = 0;
        for(int i = n-2; cnt < n/3 ; i-=2){
            ans += nums[i];
            cnt++;
        }

        return ans;
    }
};