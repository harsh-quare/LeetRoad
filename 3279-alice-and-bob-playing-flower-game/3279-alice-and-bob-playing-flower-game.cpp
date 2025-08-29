class Solution {
public:
    long long flowerGame(int n, int m) {
        int evenN = n/2;
        int oddN = n - evenN;
        int evenM = m/2;
        int oddM = m - evenM;

        return (1LL * oddN * evenM) + (1LL * evenN * oddM);
    }
};