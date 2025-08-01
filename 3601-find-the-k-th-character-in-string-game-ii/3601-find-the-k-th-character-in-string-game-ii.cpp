class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int cnt_ops = 0;
        long long val = k;
        while(val > 1){
            int jumps = ceil(log2(val));
            val -= pow(2, jumps-1);
            cnt_ops += operations[jumps-1];
        }

        return char('a' + (cnt_ops % 26));
    }
};