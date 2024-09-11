class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;

        for(int i = 31; i>=0; i--){
            bool b1 = start & (1 << i);
            bool b2 = goal & (1 << i);

            if(b1 != b2) cnt++;
        }

        return cnt;
    }
};