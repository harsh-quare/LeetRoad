class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        long long rsum = 0;
        for(int i = n-1; i >= 0; i--){
            rsum += shifts[i];
            int pos = s[i] - 'a';
            int new_pos = (pos + rsum) % 26;

            s[i] = 'a' + new_pos;
        }

        return s;
    }
};