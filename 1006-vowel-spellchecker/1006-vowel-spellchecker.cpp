class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> st(wordlist.begin(), wordlist.end());

        //map to store lowercase versions of words
        unordered_map<string, string> lower_case_map;

        //store the original case versions of words by their lowercase equivalent
        for(auto& w : wordlist){
            string w_lower = w;
            transform(w_lower.begin(), w_lower.end(), w_lower.begin(), ::tolower);
            if(lower_case_map.find(w_lower) == lower_case_map.end()) {
                lower_case_map[w_lower] = w;  //only store the first occurrence of a lowercase word
            }
        }

        for(auto& q : queries) {

            // if exact match available => take that
            if (st.count(q)) {
                ans.push_back(q);
                continue;
            }

            // convert query to lowercase
            string q1 = q;
            transform(q1.begin(), q1.end(), q1.begin(), ::tolower);

            bool found = false;

            //first, check for case-insensitive match using the lowercase map
            if(lower_case_map.find(q1) != lower_case_map.end()){
                ans.push_back(lower_case_map[q1]);  // return the original case version
                found = true;
            } 
            else{
                //check for vowel err case
                for(auto& w : wordlist){
                    if(w.length() == q.length()){
                        bool allVowelErrs = true;
                        for(int i = 0; i < w.length(); i++){
                            if(tolower(w[i]) != tolower(q[i])){
                                if(!isVowel(tolower(w[i])) || !isVowel(tolower(q[i]))){
                                    allVowelErrs = false;
                                    break;
                                }
                            }
                        }

                        if(allVowelErrs){
                            ans.push_back(w);
                            found = true;
                            break;
                        }
                    }
                }
            }

            //if no match, add empty string
            if(!found){
                ans.push_back("");
            }
        }

        return ans;
    }
};
