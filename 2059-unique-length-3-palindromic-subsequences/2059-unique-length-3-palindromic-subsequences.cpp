class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Instead of checking all the combinations of first and third character to be same, we just check the characters's left most and right most occurence. All characters in between those indices can form a palindrome.
        int n = s.size();
        int ans = 0;

        vector<pair<int, int>> vp(26, {-1, -1});
        for(int i = 0; i < n; i++){
            int id = s[i] - 'a';

            if(vp[id].first == -1) vp[id].first = i;
            vp[id].second = i;
        }

        for(int i = 0; i < 26; i++){
            int left_id = vp[i].first;
            int right_id = vp[i].second;

            if(left_id == -1) continue;

            unordered_set<char> uniq;
            for(int j = left_id + 1; j < right_id; j++){
                uniq.insert(s[j]);
            }

            ans += uniq.size();
        }

        return ans;
    }
};