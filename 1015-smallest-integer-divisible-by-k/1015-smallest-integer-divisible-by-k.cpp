class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // only if k is divisible by 2 or 5 => -1
        // or if all the %k are checked and still no number is achieved which follows the condn => -1
        if(k == 1) return 1;
        if(k % 2 == 0 || k % 5 == 0) return -1;

        int remnd = 0;
        for(int i = 1; i <= k; i++){  // only till k length is possible => bcz using modulo k => 0,1,...k-1
            remnd = (remnd*10 + 1) % k;
            if(remnd == 0) return i;
        }

        return -1;
    }
};