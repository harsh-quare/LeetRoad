class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;

        unordered_set<char> st;
        st.insert('a'), st.insert('e'), st.insert('o'), st.insert('i'), st.insert('u');

        for(int j = 0; j < n; j++){
            unordered_set<char> newSt;
            int consCnt = 0;

            for(int i = j; i < n; i++){
                char c = word[i];

                if(st.find(c) != st.end()){
                    newSt.insert(c);
                }
                else if(!isVowel(c)) consCnt++;

                if(newSt.size() == 5 && consCnt == k) ans++;

                if(consCnt > k) break;
            }
        }

        return ans;
    }
};