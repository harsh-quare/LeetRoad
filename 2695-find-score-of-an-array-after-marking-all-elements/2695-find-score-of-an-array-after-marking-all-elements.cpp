class Solution {
public:
    #define pii pair<int, int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> marked(n, false);

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            int mini = pq.top().first;
            int id = pq.top().second;
            pq.pop();

            if(marked[id] == true) continue;

            ans += mini;

            marked[id] = true;
            if(id > 0) marked[id-1] = true;
            if(id < n-1) marked[id+1] = true;
        }

        return ans;
    }
};