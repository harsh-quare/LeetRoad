class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 4LL * n * (n-1) / 2;
    }
};
// 1,5,13,25,41
//  4 8 12 16 ...  => difference
// The number of added cells at minute n, is 4*(n-1)
// total added cell => 4*(1+2+...(n-1))
// 4 * n*(n-1)/2