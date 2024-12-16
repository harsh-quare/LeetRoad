class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }

        while(k--){
            int val = pq.top().first;
            int id = pq.top().second;
            pq.pop();

            nums[id] = val*multiplier;
            pq.push({nums[id], id});
        }

        return nums;
    }
};