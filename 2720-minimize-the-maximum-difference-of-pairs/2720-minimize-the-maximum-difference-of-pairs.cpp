class Solution {
public:
    int cntPairs(int midDiffGuess, vector<int>& nums){
        int cnt = 0;
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(i+1 < n && abs(nums[i] - nums[i+1]) <= midDiffGuess){  // valid pair, continue with next pair, i+2, i+3 
                cnt++;
                i += 2;
            }
            else{
                i++;  // move to nect index, and try new pair there
            }
        }

        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(p == 0) return 0;
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n-1] - nums[0];  // highest diff possible
        int ans = 0;

        while(low <= high){
            int mid = low + (high - mid) / 2;  // guessed a difference in mid

            if(cntPairs(mid, nums) >= p){  // counting the pairs in nums having diff <= mid. if such pairs are more than required(p), we can try lesser difference value
                ans = mid;
                high = mid-1;
            }
            else{  // else try higher diff value
                low = mid + 1;
            }
        }

        return ans;
    }
};