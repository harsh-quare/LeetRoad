class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        deque<int> maxDeq;   //will be storing indexes
        //kind of max_heap: front element will be largest: and the values will be sorted in decreasing order from left to right
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> ans;

        while(right < n){
            //pop smaller values from deq
            while(!maxDeq.empty() && nums[right] > nums[maxDeq.back()]){
                maxDeq.pop_back();
            }
            //append the current index
            maxDeq.push_back(right);

            //remove left value from deq: if the left pointer has already crossed the value at front, that won't be in our k size window
            if(left > maxDeq.front()){
                maxDeq.pop_front();
            }

            if(right - left + 1 >= k){
                ans.push_back(nums[maxDeq.front()]);
                left++;
            }
            right++;
        }

        return ans;
    }
};