class Solution {
public:
    const int mod = 1e9 + 7;
    long long power(int x, long long y){
        // we need to find x^y in lesser time
        if(y == 0) return 1;

        long long ans = power(x, y/2);
        ans *= ans;
        ans %= mod;

        if(y % 2 != 0){
            ans *= x;
            ans %= mod;
        }

        return ans % mod;
    }
    int countGoodNumbers(long long n) {
        long long evens = n/2 + n%2;
        long long odds = n/2;

        return (power(5, evens) * power(4, odds)) % mod;
    }
};