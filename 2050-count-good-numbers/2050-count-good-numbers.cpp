#define mod 1000000007
class Solution {
public:   
    long long power(long long x, long long y){  //x^y
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

        long long total = (power(5, evens)*power(4, odds)) % mod;

        return total;
    }
};