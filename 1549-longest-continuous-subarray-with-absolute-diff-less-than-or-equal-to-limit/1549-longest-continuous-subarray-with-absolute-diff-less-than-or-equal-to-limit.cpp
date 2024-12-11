class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDeq, maxDeq;
        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++){
            //minDeq: storing minimum elements in current window
            while(!minDeq.empty() && nums[right] < minDeq.back()){  //current element is smaller than the back of minDq, which is storing minimums in current window
                minDeq.pop_back();
            }
            minDeq.push_back(nums[right]);

            //maxDeq: storing maximum elements in current window
            while(!maxDeq.empty() && nums[right] > maxDeq.back()){  //current element is larger than the back of maxDq, which is storing maximums in current window
                maxDeq.pop_back();
            }
            maxDeq.push_back(nums[right]);

            // Shrink the window if the condition is violated
            while(maxDeq.front() - minDeq.front() > limit){
                if(nums[left] == minDeq.front()){
                    minDeq.pop_front();
                }
                if(nums[left] == maxDeq.front()){
                    maxDeq.pop_front();
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};