class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int> pq;
        for(auto& it: nums){
            pq.push(it);
        }

        int i = 1;
        while(i < n){
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }

        i = 0;
        while(i < n){
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }
    }
};