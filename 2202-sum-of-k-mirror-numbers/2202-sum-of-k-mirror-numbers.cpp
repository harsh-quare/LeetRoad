class Solution {
public:
    long long createPalindrome(long long num, bool isOdd){
        long long x = num;
        if(isOdd){
            x /= 10;  // won't include the digit at unit place
        }

        while(x > 0){
            num = num*10 + x%10;
            x /= 10;
        }

        return num;
    }

    bool isPalBaseK(long long num, int base){
        vector<int> digs;
        while(num > 0){
            digs.push_back(num % base);
            num /= base;
        }

        int i = 0, j = digs.size()-1;
        while(i < j){
            if(digs[i++] != digs[j--]) return false;
        }

        return true;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        for(long long numLen = 1; n > 0; numLen *= 10){ //breaking condn is when n becomes 0, means smallest n numbers are achieved

            // step-1: create odd length palindromes
            for(long long i = numLen; n > 0 && i < numLen*10; i++){ // numLen = 1 => from digit 0 to 9
                long long num = createPalindrome(i, true);  // true => creating odd length palindromes
                if(isPalBaseK(num, k)){
                    ans += num;
                    n--;  // ek smallest bnda mil gya
                }
            }

            // step-2: create even length palidnromes
            for(long long i = numLen; n > 0 && i < numLen*10; i++){
                long long num = createPalindrome(i, false);  // false => creating even length palindromes
                if(isPalBaseK(num, k)){
                    ans += num;
                    n--;
                }
            }
        }

        return ans;
    }
};

//the hard task here is to optimally generate palindromes in base 10, and stop as soon as first k valid such palidromes are found.