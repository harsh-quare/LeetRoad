class Solution {
    const int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        long long typ2 = 6, typ3 = 6;  // n == 1

        for(int i = 2; i <= n; i++){
            long long newTyp2 = (3*typ2 + 2*typ3) % mod;
            long long newTyp3 = (2*typ2 + 2*typ3) % mod;

            typ2 = newTyp2;
            typ3 = newTyp3;
        }

        return (typ2 + typ3) % mod;
    }
};