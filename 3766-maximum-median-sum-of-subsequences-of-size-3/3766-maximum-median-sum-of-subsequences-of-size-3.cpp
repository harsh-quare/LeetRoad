class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());

        // for(int i = 0; i < n; i++){
        //     cout << nums[i] << endl;
        // }

        int elementsFromBeginning = n/3;
        for(int i = n-2; i >= elementsFromBeginning; i-=2){
            ans += nums[i];
        }

        return ans;
    }
};