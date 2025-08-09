class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if the number in its bit representation has only single set bit, then it's the power of 2
        if(n <= 0) return false;
        int cnt = 0;
        while(n){
            cnt += (n & 1);
            n = (n >> 1);
        }

        return (cnt == 1);
    }
};