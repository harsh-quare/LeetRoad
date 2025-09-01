class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        double ans = 0.0;
        
        for(int i = 0; i < n; i++){
            int pass = classes[i][0];
            int total = classes[i][1];

            double curr = pass / (1.0 * total);
            double next = (pass + 1) / (1.0 * (total + 1));

            ans += curr;

            double profit = next - curr;
            pq.push({profit, i});
        }

        while(extraStudents--){
            pair<double, int> p = pq.top();
            pq.pop();
            double profit = p.first;
            int idx = p.second;

            ans += profit;
            
            classes[idx][0]++;
            classes[idx][1]++;
            double curr = classes[idx][0] / (1.0 * classes[idx][1]);
            double next = (classes[idx][0] + 1) / (1.0 * (classes[idx][1] + 1));

            pq.push({next - curr, idx});
        }

        return (double)ans / (1.0 * n);
    }
};