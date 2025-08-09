class Solution {
public:
    bool isPowerOfFour(int n) {
        // for n to be the power of 4, the log4(n) value must be an integer.
        // log4(n) = log(n) / log(4);

        if(n <= 0) return false;

        // The fmod() function in C++ calculates the floating-point remainder of a division operation. => fmod(double dividend, double divisor);
        return fmod(log(n) / log(4), 1.0) == 0.0;
    }
};