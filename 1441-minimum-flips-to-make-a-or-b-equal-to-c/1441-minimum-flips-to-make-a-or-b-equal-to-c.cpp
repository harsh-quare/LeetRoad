class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i = 0; i < 32; ++i){
            bool aBit = (a >> i) & 1;
            bool bBit = (b >> i) & 1;
            bool cBit = (c >> i) & 1;

            if(!cBit){
                //If cBit is 0, set both aBit and bBit to 0
                flips += aBit + bBit;
            } 
            else if(!aBit && !bBit){
                // If cBit is 1 and both aBit and bBit are 0, flip one of them
                flips += 1;
            }
        }
        return flips;
    }
};