class Solution {
public:
    bool canRob(int mid, vector<int>& nums, int k){
        // It's always better to start early. Because we are skipping the adjacent guys, so it would be beneficial for us to start early so that we can have more number of houses to steal from
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= mid){
                count++;
                i++;  //skip next element
            }
        }

        return count >= k;  // if we can select atleast k elements
    }
    int minCapability(vector<int>& nums, int k) {
        // Answer will be an integer from nums array.
        // We need the minimum capability, so that the robber can steal from at least k houses
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canRob(mid, nums, k)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return res;
    }
};