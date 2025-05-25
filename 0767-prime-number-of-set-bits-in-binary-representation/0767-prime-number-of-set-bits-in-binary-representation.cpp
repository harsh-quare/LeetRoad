class Solution {
public:
    bool isPrime(int n){
        // for a number to be prime, it must have only 2 divisors, 1 and n
        int cnt = 0;
        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                cnt++;
                if(n/i != i) cnt++;  // to avoid repetition, 6*6
            }
        }

        return cnt == 2;
    }
    int countSetBits(int n){
        int cnt = 0;
        while(n){
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++){
            int b = countSetBits(i);
            if(isPrime(b)) cnt++;
        }
        return cnt;
    }
};