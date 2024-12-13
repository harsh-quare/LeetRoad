class Solution {
public:
    int halveArray(vector<int>& nums) {
        int steps = 0;

        double sum = 0;
        priority_queue<double> pq;
        for(auto& x: nums){
            pq.push(x);
            sum += x;
        }
        
        double half = (double)sum/2;
        while(sum > half){
            double val = pq.top();
            pq.pop();

            double new_val = (double)val / 2;
            pq.push(new_val);

            sum -= new_val;

            steps++;
        }

        return steps;
    }
};