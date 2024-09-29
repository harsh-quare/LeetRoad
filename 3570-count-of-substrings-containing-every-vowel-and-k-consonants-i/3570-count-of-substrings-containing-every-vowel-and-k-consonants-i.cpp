class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int countOfSubstrings(string word, int k) {
        int ans = 0;
        int minLen = k+5;
        if(word.length() < minLen) return 0;
        for(int i = 0; i < word.length(); i++){
            unordered_set<char> st;
            int vowCnt = 0, consCnt = 0;
            for(int j = i; j < word.length(); j++){
                if(isVowel(word[j]) && st.find(word[j]) == st.end()) {
                    vowCnt++; 
                    st.insert(word[j]);
                }
                else if(!isVowel(word[j])) consCnt++;
                if(vowCnt == 5 && consCnt == k) ans++;
            }
        }

        return ans;
    }
};