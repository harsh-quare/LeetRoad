#define mod 1000000007
class Solution {
public:   
    long long power(long long val, long long cnt){
        long long ans = 1;

        while(cnt > 0){
            if(cnt % 2 == 1){
                ans *= val;
                ans %= mod;
            }

            val *= val;
            val %= mod;
            cnt /= 2;
        }

        return ans % mod;
    } 
    int countGoodNumbers(long long n) {
        long long evens = n/2 + n % 2;
        long long odds = n/2;

        long long total = (power(5, evens)*power(4, odds)) % mod;

        return total;
    }
};