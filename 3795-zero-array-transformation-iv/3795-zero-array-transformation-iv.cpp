class Solution {
public:
    bool canZero(int mid, vector<int>& nums, vector<vector<int>>& q, int n) {
        //for each index, track possible decrements
        for(int i = 0; i < n; i++){
            vector<bool> possible(nums[i] + 1, false); //can we achieve this decrement???
            possible[0] = true; // Empty subset
            
            for(int j = 0; j < mid; j++){
                int l = q[j][0], r = q[j][1], x = q[j][2];
                if(i < l || i > r) continue; // i not in range
                
                //shift possible values by x
                for(int val = nums[i]; val >= x; val--){
                    if(possible[val - x]){
                        possible[val] = true;
                    }
                }
            }
            if(!possible[nums[i]]) return false; //cannot make nums[i] exactly 0
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int low = 0;
        int high = queries.size();  // applying all queries

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canZero(mid, nums, queries, n)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};