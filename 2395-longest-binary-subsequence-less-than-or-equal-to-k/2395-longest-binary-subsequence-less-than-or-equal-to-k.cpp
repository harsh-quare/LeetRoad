class Solution {
public:
    int longestSubsequence(string s, int k) {
        // har ek index pe jaake puch lo ki, kya 'k' ke paas power h, iss index ko lene ki, if k >= s[i]*2^(n-1-i)
        // and go from right to left, bcz left side me higher powers hogi 2 ki, to vaha se jaldi khatam ho jayega 'k'
        // so it's better to consume 1's from LSB side.
        int n = s.size();
        int len = 0;
        long long val = 0;
        int bit_pos = 0;

        //traverse from right to left (LSB to MSB)
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0'){
                len++;  // can always include
            } 
            else{
                if(bit_pos < 32 && (val + (1LL << bit_pos)) <= k){  // bit_pos only 32 tk allowed hoti h
                    val += (1LL << bit_pos);
                    len++;
                }
            }
            bit_pos++;
        }

        return len;
    }
};
