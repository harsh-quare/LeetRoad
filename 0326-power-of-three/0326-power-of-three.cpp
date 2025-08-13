class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPow3 = 1162261467;  // largest power of 3 is: 3^19 < INT_MAX
        return n > 0 && (maxPow3 % n == 0);
    }
};