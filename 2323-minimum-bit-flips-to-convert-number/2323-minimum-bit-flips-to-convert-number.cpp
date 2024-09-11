class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorRes = start ^ goal;

        int cnt = 0;
        while(xorRes > 0){
            cnt += (xorRes & 1);
            xorRes >>= 1;
        }

        return cnt;
    }
};