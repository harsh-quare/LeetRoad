class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int cnt = 1;  // original string as a single substring is always gonna be the answer in best case
        unordered_set<char> st;

        for(int i = 0; i < n; i++){
            char c = s[i];
            if(st.find(c) != st.end()){
                cnt++;
                st.clear();
            }
            st.insert(c);
        }

        return cnt;
    }
};