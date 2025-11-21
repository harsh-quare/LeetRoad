class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        // get left most and right most index for each character, and the count uniqs between those 2 indexes
        vector<pair<int, int>> vp(26, {-1, -1});
        for(int i = 0; i < n; i++){
            pair<int, int> cur = vp[s[i] - 'a'];
            if(cur.first != -1) cur.first = min(cur.first, i);
            else cur.first = i;

            if(cur.second != -1) cur.second = max(cur.second, i);
            else cur.second = i;

            vp[s[i] - 'a'] = cur;
        }

        int ans = 0;
        for(auto p: vp){
            int l = p.first;
            int r = p.second;

            if(l != -1 && r-l+1 >= 3){
                unordered_set<char> st;
                for(int i = l+1; i < r; i++){
                    st.insert(s[i]);
                }

                ans += st.size();
            }
        }

        return ans;
    }
};