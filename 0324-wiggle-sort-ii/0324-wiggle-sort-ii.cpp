class Solution {
public:
    #define pii pair<int, int>
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }

        priority_queue<pii> pq;
        for(auto& it: mp){
            pq.push({it.first, it.second});
        }

        int i = 1;
        while(i < n){
            auto p = pq.top();
            pq.pop();
            nums[i] = p.first;
            p.second--;
            if(p.second != 0) pq.push({p.first, p.second});
            i += 2;
        }

        i = 0;
        while(i < n){
            auto p = pq.top();
            pq.pop();
            nums[i] = p.first;
            p.second--;
            if(p.second != 0) pq.push({p.first, p.second});
            i += 2;
        }
    }
};