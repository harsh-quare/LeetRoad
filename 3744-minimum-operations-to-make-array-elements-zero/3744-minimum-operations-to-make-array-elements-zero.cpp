class Solution {
public:
    long long solve(long long l, long long r){
        long long cnt = 0, lo = 1;
        int k = 1; //level (sbke niklenge)
        while(lo <= r){
            long long hi = lo*4 - 1;
            long long left = max(l, lo);
            long long right = min(r, hi);

            if(left <= right) cnt += (right - left + 1) * k;

            lo *= 4;  //next power of 4
            k++;  //level bdh gye
        }
        return cnt;
    }
    
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;

        for(auto& q: queries){
            long long l = q[0];
            long long r = q[1];

            long long ops = solve(l, r);
            res += (ops + 1) / 2;  // ceiling division
        }

        return res;
    }
};