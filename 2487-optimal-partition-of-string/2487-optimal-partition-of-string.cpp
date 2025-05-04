class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        if(n <= 1) return n;

        vector<int> charMp(26, 0);
        int ans = 1;

        for(int i = 0; i < n; i++){
            if(charMp[s[i]-'a'] != 0){
                // not the first encounter, repetition mil gya, to new string start kr do
                ans++;
                for(int j = 0; j < 26; j++){
                    charMp[j] = 0; // reset entire map, bcz new string starts
                }
            }
            charMp[s[i]-'a'] = 1;  // first encounter in current string
        }
        return ans;
    }
};