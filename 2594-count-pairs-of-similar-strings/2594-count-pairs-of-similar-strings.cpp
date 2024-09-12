class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;

        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            unordered_set<char> st;
            for(auto ch: s){
                st.insert(ch);
            }

            for(int j = i+1; j < words.size(); j++){
                bool isValid = true;
                string s2 = words[j];
                unordered_set<char> tmp;
                for(auto ch: s2){
                    if(st.find(ch) == st.end()){  
                        //agar current character is string ka nhi h purane ke set me, to ye string to valid nhi ho skti
                        isValid = false; 
                        break;
                    }
                    tmp.insert(ch);
                }

                if(isValid == true && tmp.size() == st.size()) cnt++;
            }
        }

        return cnt;
    }
};