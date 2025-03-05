class Solution {
public:
    long long coloredCells(int n) {
        // The pattern is 1,3,5,7,9 cells in the middle row.
        // and other rows are repeating considering middle row as mirror plane

        if(n == 1) return 1;

        long long ans = 0;
        ans += (long long)2*n - 1;  // middle row
        
        // remaining are doubled
        for(long x = 1; x < 2*n-1; x++){
            if(x % 2 != 0){
                ans += (long long)x * 2;
            }
        }

        return ans;
    }
};
// n = 1 => 1*1
// n = 2 => 1*2 + 3*1
// n = 3 => 1*2 + 3*2 + 5*1
// n = 4 => 1*2 + 3*2 + 5*2 + 7*1
// n = 5 => 1*2 + 3*2 + 5*2 + 7*2 + 9