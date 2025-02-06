class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int val = q.front();
                q.pop();
                
                if(val == goal) return steps;

                for(int i = 0; i < n; i++){
                    int a = val + nums[i];
                    int b = val - nums[i];
                    int c = val ^ nums[i];

                    if(a == goal || b == goal || c == goal) return steps + 1;  // solves the problem of going out of bound once

                    if(a >= 0 && a <= 1000 && !vis.count(a)) {
                        q.push(a);
                        vis.insert(a);
                    }
                    if(b >= 0 && b <= 1000 && !vis.count(b)) {
                        q.push(b);
                        vis.insert(b);
                    }
                    if(c >= 0 && c <= 1000 && !vis.count(c)) {
                        q.push(c);
                        vis.insert(c);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};