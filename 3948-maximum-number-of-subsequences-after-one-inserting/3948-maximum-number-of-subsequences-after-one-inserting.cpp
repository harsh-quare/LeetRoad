class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        // count number of subseqs matching "LCT" in original string
        long long orgLCT = 0;
        long long l = 0, lc = 0;
        for(char& c: s){
            if(c == 'L') l++;
            else if(c == 'C') lc += l;
            else if(c == 'T') orgLCT += lc;
        }

        // We can't try inserting each character {L,C,T} at every position and calculate number of "LCT" subseqs for those resulting strings
        // That's why we need to precompute, for every index, count of "L" and "LC" in prefix and "T" and "CT" in suffix
        // It will allow us to directly calculate the extra LCT strings after adding each character each index

        // Calculate prefix "L"(for when we have "CT" suffix) and prefix "LC" (for when we have "T" suffix)
        vector<long long> prefixL(n+1);
        vector<long long> prefixLC(n+1);
        l = 0, lc = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') l++;
            else if(s[i] == 'C') lc += l;

            prefixL[i + 1] = l;
            prefixLC[i + 1] = lc;
        }

        // Calculate suffix "T"(for when we have "LC" prefix) and suffix "CT" (for when we have "L" prefix)
        vector<long long> suffixT(n+1);
        vector<long long> suffixCT(n+1);
        long long t = 0, ct = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'T') t++;
            else if(s[i] == 'C') ct += t;

            suffixT[i] = t;
            suffixCT[i] = ct;
        }

        // try inserting every char at each index
        long long maxLCT = orgLCT;
        for(int i = 0; i <= n; i++){
            long long addingL = suffixCT[i];
            long long addingC = prefixL[i] * suffixT[i];
            long long addingT = prefixLC[i];

            maxLCT = max({maxLCT, orgLCT + addingL, orgLCT + addingC, orgLCT + addingT});
        }

        return maxLCT;
    }
};