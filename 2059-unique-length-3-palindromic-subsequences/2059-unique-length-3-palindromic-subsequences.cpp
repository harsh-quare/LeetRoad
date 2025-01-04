class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Instead of checking all the combinations of first and third character to be same, we just check the characters's left most and right most occurence. All characters in between those indices can form a palindrome.
        int n = s.size();
        int ans = 0;
        
        unordered_set<char> chars;
        for(auto& ch: s){
            chars.insert(ch);
        }

        for(auto& ch: chars){
            int left_id = -1;
            int right_id = -1;

            for(int i = 0; i < n; i++){
                if(s[i] == ch){
                    if(left_id == -1) left_id = i;
                    right_id = i;
                }
            }

            // Now, we got the first and last occ of current character
            // count unique chars between that part
            unordered_set<char> uniq_bw_both;
            for(int i = left_id + 1; i < right_id; i++){
                uniq_bw_both.insert(s[i]);
            }

            ans += uniq_bw_both.size();
        }

        return ans;
    }
};