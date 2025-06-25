class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // Line sweep
        int n = nums.size();
        vector<int> ans;
        vector<int> help(n, false);
        int left_id = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                left_id = i;
            }

            if(left_id != -1 && i - left_id <= k) help[i] = true;
        }

        int right_id = n;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] == key){
                right_id = i;
            }

            if(right_id != n && right_id - i <= k) help[i] = true;
        }

        for(int i = 0; i < n; i++){
            if(help[i] == true) ans.push_back(i);
        }

        return ans;
    }
};