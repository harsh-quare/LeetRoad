class Solution {
public:
    int bsLastNeg(vector<int>& nums, int n){
        int lo = 0, hi = n-1;
        int ans = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] < 0){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
    }
    int bsFirstPos(vector<int>& nums, int n){
        int lo = 0, hi = n-1;
        int ans = n;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > 0){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return ans;
    }
    int maximumCount(vector<int>& nums) {
        // the array is sorted in non-decreasing order, so we can apply binary search on it to find the last point of negative number and first point of positive number
        int n = nums.size();
        int lastNeg = bsLastNeg(nums, n);
        int firstPos = bsFirstPos(nums, n);

        return max(lastNeg + 1, n - firstPos);
    }
};