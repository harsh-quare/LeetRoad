class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c== 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        string t = s;
        vector<char> vowels;
        for(int i = 0; i < t.size(); i++){
            if(isVowel(t[i])){
                vowels.push_back(t[i]);
            }
        }

        if(vowels.empty()) return s;
        sort(vowels.begin(), vowels.end());

        int id = 0;
        for(int i = 0; i < t.size(); i++){
            if(isVowel(t[i])){
                t[i] = vowels[id];
                id++;
            }
        }

        return t;
    }
};