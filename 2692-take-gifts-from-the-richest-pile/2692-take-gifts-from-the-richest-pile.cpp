class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long total = 0;
        priority_queue<int> pq;
        for(auto& x: gifts){
            pq.push(x);
            total += x;
        }

        while(k--){
            int maxi = pq.top();
            pq.pop();

            int val = sqrt(maxi);
            pq.push(val);
            total = total - (maxi - val);
        }

        return total;
    }
};