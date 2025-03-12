class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // the array is sorted in non-decreasing order, so we can apply binary search on it to find the last point of negative number and first point of positive number
        int n = nums.size();
        auto lb = lower_bound(nums.begin(), nums.end(), 0);
        auto ub = upper_bound(nums.begin(), nums.end(), 0);

        int neg = lb - nums.begin();
        int pos = nums.end() - ub;

        return max(neg, pos);
    }
};