class Solution {
public:
    bool canZeroArr(vector<int> nums, vector<vector<int>>& queries, int k, int n){  //nums will be passed by value, not by reference bcz we don't want the changes(nums[i] -= dec) to happen in original array
        vector<int> diff(n+1, 0);
        
        for(int i = 0; i < k; i++){ 
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if(r+1 < n) diff[r+1] += val;
        }
        
        int dec = 0;
        for(int i = 0; i < n; i++){
            dec += diff[i];
            nums[i] += dec;
            if(nums[i] > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        int low = 0, high = m;
        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canZeroArr(nums, queries, mid, n)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};