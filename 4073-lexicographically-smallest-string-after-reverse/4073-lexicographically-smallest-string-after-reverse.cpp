class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();

        string ans = s;
        for(int i = 0; i < n; i++){
            string cur = s;
            reverse(cur.begin(), cur.begin()+i+1);
            if(cur < ans) ans = cur;

            cur = s;
            reverse(cur.begin()+i+1, cur.end());
            if(cur < ans) ans = cur;
        }

        return ans;
    }
};