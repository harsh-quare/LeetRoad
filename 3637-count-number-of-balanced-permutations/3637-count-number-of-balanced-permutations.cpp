class Solution {
public:
    int n;
    int totalDigSum;
    const int mod = 1e9 + 7;
    long long totalPermPossible;

    int findPower(long long a, long long b){  // using binary exponentiation
        if(b == 0) return 1;

        long long half = findPower(a, b/2);
        long long res = (half * half) % mod;
        if(b % 2 == 1){
            res = (res * a) % mod;
        }

        return res;
    }

    int solve(int digit, int evenIdxDigCnt, int curSum, vector<int>& freq, vector<long long>& fermatFact){
        if(digit == 10){
            if(curSum == totalDigSum/2 && evenIdxDigCnt == (n+1)/2){
                return totalPermPossible;
            } 
            return 0;
        }

        long long ways = 0;
        for(int cnt = 0; cnt <= min(freq[digit], (n+1)/2 - evenIdxDigCnt); cnt++){
            int evenPosCnt = cnt;
            int oddPosCnt = freq[digit] - evenPosCnt;

            // long long div = 1/evenPosCnt! * 1/oddPosCnt! % mod
            long long div = (fermatFact[evenPosCnt] * fermatFact[oddPosCnt]) % mod; // 1/f1! * 1/f2!

            long long val = solve(digit + 1, evenIdxDigCnt + evenPosCnt, curSum + digit*cnt, freq, fermatFact);

            ways = (ways + (val * div) % mod) % mod;
        }

        return ways;
    }
    int countBalancedPermutations(string num) {
        n = num.size();
        totalDigSum = 0;
        vector<int> freq(10, 0);

        for(int i = 0; i < n; i++){
            totalDigSum += (num[i] - '0');
            freq[num[i]-'0']++;
        }

        if(totalDigSum % 2 != 0) return 0;

        //Precompute factorials
        vector<long long> fac(n+1, 1);  // we are computing factorials, bcz they will be divided while calculating ways, n!/f!, means we will need to divide by the frequency of the digits, that's why we are precomputing them
        fac[0] = 1;
        fac[1] = 1;
        for(int i = 2; i <= n; i++){
            fac[i] = (fac[i-1] * i) % mod;
        }

        //Precompute inverse factorials => Fermet Factorials => ((1/x)%M)
        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++){
            fermatFact[i] = findPower(fac[i], mod-2) % mod;
        }

        totalPermPossible = (1LL * fac[(n+1)/2] * fac[n/2]) % mod;

        int digit = 0;
        int evenIdxDigCnt = 0;
        int curSum = 0;
        return solve(digit, evenIdxDigCnt, curSum, freq, fermatFact);
    }
};