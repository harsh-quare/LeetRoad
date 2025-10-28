class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int pref = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(pref - (total - pref) == 0) ans += 2;
                else if( abs(pref - (total-pref)) == 1) ans += 1;
            }
            pref += nums[i];
        }

        return ans;
    }
};