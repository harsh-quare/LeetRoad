class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int n = s.size();
        int ans = 0;
        int zeros = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == '1') ones--;
            else zeros++;

            ans = max(ans, zeros + ones);
        }

        return ans;
    }
};