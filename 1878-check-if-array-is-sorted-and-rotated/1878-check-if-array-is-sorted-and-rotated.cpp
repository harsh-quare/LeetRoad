class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i < n-1 && nums[i] > nums[i+1]){
                cnt++;
            }
        }

        if(cnt >= 2 || (cnt > 0 && nums[0] < nums[n-1])) return false;

        return true;
    }
};