class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n){
            if(n == 1) return true;
            if(n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};