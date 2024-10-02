class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        // sort(nums.begin(), nums.end());
        int smaller = 0;
        int equal = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target) smaller++;
            else if(nums[i] == target) equal++;
        }

        for(int i = smaller; i < smaller + equal; i++){
            ans.push_back(i);
        }

        return ans;
    }
};