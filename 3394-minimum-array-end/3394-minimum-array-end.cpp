class Solution {
public:
    long long minEnd(int n, int x) {
        // edge cases: 7: 111, right me koi jagah nhi h, to left me badhana padega
        long long val = x;  //first value is always x, minimum of all
        long long mask = n-1;
        
        int l1 = 0, l2 = 0;

        while(mask){
            long long m = (mask & 1);
            mask >>= 1;

            while((1LL << l2) & val){
                l2++;
            }

            val |= (m << l2);
            l2++;
        }

        return val;
    }
};