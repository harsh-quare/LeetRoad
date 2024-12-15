class Solution {
public:
    #define pdi pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pdi> pq;
        for(int i = 0; i < n; i++){
            int p = classes[i][0];
            int t = classes[i][1];

            double cur = (double)p/t;
            double nxt = (double)(p+1) / (t+1);

            // maxDiff wale bnde chahiye
            pq.push({abs(cur - nxt), i});
        }

        while(extraStudents--){
            // cout << pq.top().first << " " << pq.top().second << endl;
            int id = pq.top().second;
            pq.pop();

            int p = classes[id][0] + 1;
            int t = classes[id][1] + 1;
            classes[id][0] = p;
            classes[id][1] = t;

            double cur = (double)p/t;
            double nxt = (double)(p+1) / (t+1);

            // maxDiff wale bnde chahiye
            pq.push({abs(cur - nxt), id});
        }

        double ans = 0;
        for(int i = 0; i < n; i++){
            int p = classes[i][0];
            int t = classes[i][1];

            // cout << p << " " << t << endl;

            double cur = (double)p/t;
            ans += cur;
        }

        return ans / n;
    }
};