class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // for the subarray to be continuous, the difference b/w max and min element in the subarray should be b/w [0,2]
        int n = nums.size();
        long long ans = 0;

        int left = 0, right = 0;
        deque<int> maxDq, minDq;
        while(right < n){
            while(!maxDq.empty() && nums[right] > nums[maxDq.back()]){
                maxDq.pop_back();
            }
            maxDq.push_back(right);
 
            while(!minDq.empty() && nums[right] < nums[minDq.back()]){
                minDq.pop_back();
            }
            minDq.push_back(right);

            //condition violate kr rhi h to window ko valid banao
            while(nums[maxDq.front()] - nums[minDq.front()] > 2){
                if(left == maxDq.front()){
                    maxDq.pop_front();
                }
                if(left == minDq.front()){
                    minDq.pop_front();
                }
                left++;
            }

            ans += (right - left + 1);
            right++;
        }

        return ans;
    }
};