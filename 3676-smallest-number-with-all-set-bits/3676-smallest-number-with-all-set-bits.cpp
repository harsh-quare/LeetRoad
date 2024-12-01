class Solution {
public:
    int smallestNumber(int n) {
        //n me saare 0's ko 1 me convert kr do
        for(int mask = 1; mask < n; mask <<= 1){
            n |= mask;
        }

        return n;
    }
};