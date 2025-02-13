class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto& x: nums) {
            pq.push(x);
        }

        int cnt = 0;
        while(true){
            if(pq.size() < 2){
                return pq.top() >= k ? cnt : -1;
            }
            else{
                if(pq.top() >= k) return cnt;
                
                long long x = pq.top();
                pq.pop();
                long long y = pq.top();
                pq.pop();

                long long newVal = (long long)min(x, y)*2 + max(x, y);
                pq.push(newVal);

                cnt++;
            }
        }

        return cnt;
    }
};