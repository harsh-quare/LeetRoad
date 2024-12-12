class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while(k--){
            int maxi = pq.top();
            pq.pop();

            int val = sqrt(maxi);
            pq.push(val);
        }

        long long total = 0;
        while(!pq.empty()){
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};