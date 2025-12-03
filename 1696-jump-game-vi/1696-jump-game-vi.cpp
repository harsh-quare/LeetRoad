class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n, 0);  // score for each index => next max value in i+1 -> i+k
        // we need the maximum value in (i+1,...i+k) for each i => to decide the next jump 
        priority_queue<pair<int, int>> pq;

        for(int i = n-1; i >= 0; i--){
            while(!pq.empty() && pq.top().second > i+k){
                pq.pop();
            }

            // Now the pq has the maximum scored guy on the top who is also in range i+1 -> i+k
            score[i] = nums[i];
            score[i] += (!pq.empty() ? pq.top().first : 0);

            pq.push({score[i], i});
        }

        return score[0];
    }
};