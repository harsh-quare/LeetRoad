class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int smaller = 0, eq = 0;
        for(int& x: nums){
            if(x < pivot){
                smaller++;
            }
            if(x == pivot){
                eq++;
            }
        }

        int i = 0;
        int j = smaller; 
        int k = (smaller + eq);

        vector<int> ans(n);
        for(int id = 0; id < n; id++){
            if(nums[id] < pivot){
                ans[i] = nums[id];
                i++;
            }
            else if(nums[id] == pivot){
                ans[j] = nums[id];
                j++;
            }
            else{
                ans[k] = nums[id];
                k++;
            }
        }

        return ans;
    }
};