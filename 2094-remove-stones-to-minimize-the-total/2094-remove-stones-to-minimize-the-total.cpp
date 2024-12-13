class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int total = 0;
        priority_queue<int> pq;
        for(int& x: piles){
            pq.push(x);
            total += x;
        }

        while(k--){
            int val = pq.top();
            pq.pop();
            
            int floor_val = val / 2;
            pq.push(val - floor_val);  //remove the floor_val from original value
            
            total = total - floor_val;  //remove the value from the total that was removed from the original value
        }

        return total;
    }
};