const int MOD = 1e9 + 7;
class Solution {
public:

    // Binary exponentiation
    int findPower(long long a, long long b){
        if(b == 0) return 1;

        long long half = findPower(a, b/2);
        long long ans = (half * half) % MOD;

        if(b % 2 == 1){
            return ans = (ans * a) % MOD;
        }

        return ans;
    }
    // nCr nikalna h
    long long nCr(int n, int r, vector<long long>& fact, vector<long long>& fermatFact){
        // (n!/((n-r)!*r!)) % MOD
        return fact[n] * fermatFact[n-r] % MOD * fermatFact[r]  % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(n+1, 1);
        for(int i = 2; i <= n; i++){
            fact[i] = (fact[i-1] * i) % MOD;
        }

        // inverse factorial bhi precalculate krlo => using fermat little theorem
        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++){
            fermatFact[i] = findPower(fact[i], MOD-2);
        }
        long long ans = nCr(n-1, k, fact, fermatFact);

        // ans = ans * m * pow((m-1), n-k-1);
        ans = (ans * m) % MOD;
        ans = (ans * findPower(m-1, n-k-1)) % MOD;  // findPower is the binary exponentiation method using binary exponentiation => log(n-k-1) => T.C.

        return ans;
    }
};

// total such places are: (n-1)
// to put exactly k => (n-1)_C_k
// and then total ways to put those
// try to put elements at places
// let's say we want exactly 2 pairs, range is 1 to m, and size is 6
// for i=0, i=1, we select this pair, i=0 can be selected from 'm' elements, and automatically i=1, will be same as i=0 => this pair is = m ways
// then i=2, is a random place, so it will be (m-1) ways
// then i=3, i=4 is the next pair, so it will be (m-1)*1 ways
// then finally i=5 => (m-1) ways
// total => m*(m-1)^3 ways => m*(m-1)^(n-k-1) ways

// final answer = (n-1)Ck * m*(m-1)^(n-k-1)
// main tricky part is to use fermat little theorem to calculate the n-1Ck % mod