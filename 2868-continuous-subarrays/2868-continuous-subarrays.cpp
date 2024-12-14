class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // For the subarray to be continuous, the difference between max and min elements should be within [0, 2]
        int n = nums.size();
        long long ans = 0;

        int left = 0, right = 0;
        deque<int> maxDq, minDq;

        while(right < n){
            //Maintain max deque
            while(!maxDq.empty() && nums[right] > nums[maxDq.back()]){
                maxDq.pop_back();
            }
            maxDq.push_back(right);

            //Maintain min deque
            while(!minDq.empty() && nums[right] < nums[minDq.back()]){
                minDq.pop_back();
            }
            minDq.push_back(right);

            //Shrink the window if the condition is violated
            while(nums[maxDq.front()] - nums[minDq.front()] > 2){
                if(left == maxDq.front()){
                    maxDq.pop_front();
                }
                if(left == minDq.front()){
                    minDq.pop_front();
                }
                left++;
            }

            //Count valid subarrays
            ans += (right - left + 1);

            //Move the right pointer forward
            right++;
        }

        return ans;
    }
};
