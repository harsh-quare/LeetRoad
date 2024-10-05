class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2, left = mid-1, right = mid+1;
        long long cnt=0;
        cnt += abs(k - nums[mid]);
        for(int i = left; i>=0; i--){
            if(nums[i] > k){
                cnt += nums[i]-k;
            }
            else break;
        }
        for(int i = right; i<n; i++){
            if(nums[i] < k){
                cnt += k-nums[i];
            }
            else break;
        }
        return cnt;
    }
};