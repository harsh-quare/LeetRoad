class Solution {
public:
    long long solve(int l, int r){
        long long cnt = 0;
        long long left = 1;  // right = 4*left - 1
        long long steps = 1;

        while(left <= r){
            long long right = 4*left - 1;

            long long st = max(left, (long long)l);
            long long end = min(right, (long long)r);

            if(end >= st) cnt += (end-st+1) * steps;

            left = left * 4;  // update for next range
            steps += 1;
        }

        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for(auto& q: queries){
            int l = q[0];
            int r = q[1];

            long long steps = solve(l, r);

            ans += (steps + 1) / 2;  // ceiling value
        }

        return ans;
    }
};

// left -> right: steps
// 1 -> 3: 1 
// 4 -> 15: 2
// 16 -> 63: 3
// 64 -> 255: 4