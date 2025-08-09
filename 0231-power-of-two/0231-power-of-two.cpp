class Solution {
public:
    bool isPowerOfTwo(int n) {
        // for n to be the power of 2, the log2(n) value must be an integer.
        // log2(n) = log(n) / log(2);

        // if(n <= 0) return false;

        // // The fmod() function in C++ calculates the floating-point remainder of a division operation. => fmod(double dividend, double divisor);
        // return fmod(log(n) / log(2), 1.0) == 0.0;

        if (n <= 0) return false;
        double log2n = log(n) / log(2);
        return fabs(log2n - round(log2n)) < 1e-10;  // Use an epsilon
    }
};