class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n-1; i++){
            if(nums[i] == nums[i-1]) continue;  // same valley or hill

            int right_neq = n;
            for(int j = i+1; j < n; j++){
                if(nums[j] != nums[i]){
                    right_neq = j;
                    break;
                }
            }

            int left_neq = -1;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] != nums[j]){
                    left_neq = j;
                    break;
                }
            }

            if(right_neq != n && left_neq != -1){
                if( (nums[i] > nums[left_neq] && nums[i] > nums[right_neq]) || 
                    (nums[i] < nums[left_neq] && nums[i] < nums[right_neq]) ) {
                        cnt++;
                        cout << i << endl;
                }
            }
        }

        return cnt;
    }
};