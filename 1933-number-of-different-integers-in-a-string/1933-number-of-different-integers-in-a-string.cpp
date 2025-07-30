class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        unordered_set<string> st;
        int i = 0, j = 0;
        while(j < n){
            if(isdigit(word[j])){
                i = j;  // mark it as starting point
                while(j < n && isdigit(word[j])){
                    j++;
                }
                // digits ki train khatam ho gyi => complete integer mil gya
                // agar isme leading zeros h, to hata do
                while(word[i] == '0') i++;
                if(j-i == 0) st.insert("0");
                else st.insert(word.substr(i, j-i));
            }
            else{
                j++;
            }
        }

        // ab jo strings aayi h, unme leading zeros hata do

        return st.size();
    }
};