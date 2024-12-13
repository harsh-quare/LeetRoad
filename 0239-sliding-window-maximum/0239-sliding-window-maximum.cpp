class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() < i - k + 1){  //front wala index, k size window me nhi h
                dq.pop_front();
            }

            //ab current element ko daal ke dekho and then decide kro ki max element kon h iss window ka
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);  //push the index

            if(i >= k-1) ans.push_back(nums[dq.front()]);  //k size window tbhi possible h jab right pointer atleast k-1 pe ho
        }

        return ans;
    }
};