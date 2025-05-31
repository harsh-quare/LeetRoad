class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int prev = -1;

        while(j < n){
            nums[i++] = nums[j];
            int k = j;
            while(k < n && nums[j] == nums[k]){
                k++;
            }
            // ab k next element pe hoga
            j = k;
        }

        return i;    
    }
};