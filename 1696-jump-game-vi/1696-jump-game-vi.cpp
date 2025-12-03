class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        // score for each index => current value + next max value in i+1 -> i+k
        // we need the maximum value in (i+1,...i+k) for each i => to decide the next jump 

        long long cur = 0;
        deque<int> dq;  // dq.front() is the maximum element
        for(int i = n-1; i >= 0; i--){
            cur = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);

            while(!dq.empty() && nums[dq.back()] < cur){  // remove all the smaller results greedily as they wont get used anyways (This helps the monoqueue to remain sorted)
                dq.pop_back();
            }

            dq.push_back(i);

            // erase all the indices in deque that are greater than or equal to i+k
            if(dq.front() >= i+k){
                dq.pop_front();
            }

            nums[i] = cur;
        }

        return cur;
    }
};