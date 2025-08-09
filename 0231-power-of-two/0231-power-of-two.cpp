class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x = pow(2, 30);  // biggest possible number which is power of 2. It must be divisible by any power of 2
        return n > 0 && (x % n == 0);
    }
};