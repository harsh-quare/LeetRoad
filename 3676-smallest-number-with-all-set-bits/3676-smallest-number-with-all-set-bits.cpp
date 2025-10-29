class Solution {
public:
    int smallestNumber(int n) {
        int p = 1;

        while(n){
            n /= 2;
            p *= 2;
        }

        return p-1;
    }
};